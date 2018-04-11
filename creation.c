/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int         createFarm(t_antFarm *farm, char *line, int result)
{
    while (result == 1 && get_next_line(0, &line) > 0)
    {
        line = ft_strtrim(line);//leak could happen here.s
        ft_putendl(line);
        if (isNumAnts(line, farm) == -1)
            result = 0;
        else if (isNumAnts(line, farm) == 1)
            farm->numAnts = ft_atoi(line);
        else if (isRoom(line, farm) == 1)
            createRoom(farm, line);
        else if (isLink(line, farm) == 1)
            createLink(farm, line);
        else if (isCommand(line, farm) == 1)
            ;//we do nothing because isCommand takes care of everthing internally
        else if (isComment(line) == 1)
            continue ;
        else
            result = 0;
    }
    return (result);
}

int         createRoom(t_antFarm *farm, char *line)//name here includes the real name and coord e.g 1 23 4: 1 is the actual name but we pass the whole line. we'll process it in this function
{
    t_room      *room;
    char        **split;

    room = (t_room*)malloc(sizeof(t_room));
    if (room == NULL)//malloc error. either we ran out of memory or something happened during malloc'ing.
        return (0);
    else
    {
        split = ft_strsplit(line, ' ');
        room->name = ft_strdup(split[0]);
        room->visited = 0;
        room->visitedBy = NULL;
        room->pathMaster = NULL;
        room->lvl = 0;
        room->linked = NULL;
        room->next = NULL;
        if (farm->allRooms == NULL)// if we create this room and we find that this is actually the first room, then we assign it to be the farm's allRooms attribute bcos currently there's only it
            farm->allRooms = room;
        else //else we just add it to linkedlist <allRooms>. we do this by making its "next" point to allRooms then make.this means this will be the new head of linkedlist allRooms 
        {
            room->next = farm->allRooms;
            farm->allRooms = room;
        }
        split = (char**)ft_clear_2d((void**)split);
        return (1);//room successfully created and added to the list of allRooms.
    }
}

int         createLink(t_antFarm *farm, char *line)//here line is like this 1-2: a link btwin room 1 and 2. we'll do the spliting in this fucntion
{
    char    **split;
    t_room  *r1;
    t_room  *r2;

    split = ft_strsplit(line, '-');
    r1 = getRoomFromFarm(farm, split[0]); //gets the 1st room
    r2 = getRoomFromFarm(farm, split[1]); //gets the 2nd room
    //now we need to add r1 to r2's linked rooms and vice versa
    //if either of the two dont have linked rooms yet, then we have to malloc space for that.
    //bellow is for adding r2 to r1;
    //but first we check if these rooms are not already linked to each other
    if (ft_contains(r1->linked, r2->name) == 1)
        return (1);
    else
    {
        addLink(&r1, r2->name);//& is there because we're gonna update room r1's attributes. i.e we're gonna add r2's name to its linked rooms
        addLink(&r2, r1->name);
        return (1);
    }
}

int         createAnts(t_antFarm *farm)
{
    int     index;
    t_ant   *ant;

    index = farm->numAnts;
    while (index > 0)
    {
        if ((ant = (t_ant*)malloc(sizeof(t_ant))) == NULL)
            return (0);//malloc error
        ant->antNum = index;
        ant->next = NULL;
        ant->pathTravelThru = NULL;
        ant->distanceCovered = 0;
        ant->turnToMove = 0;
        if (farm->allAnts == NULL)
            farm->allAnts = ant;
        else
        {
            ant->next = farm->allAnts;
            farm->allAnts = ant;
        }
        index--;
    }
    return (1);
}

t_path      *createPath(t_antFarm *farm, int distance)
{
    t_path  *path;

    path = (t_path*)malloc(sizeof(t_path));
    if (path == NULL)
        return (NULL);//if mem was not alloc
    else
    {
        path->next = NULL;
        path->distance = distance;
        path->roomsInPath = (char**)malloc(sizeof(char*)*(distance + 1));
        path->roomsInPath[distance] = NULL;
        path->roomsInPath[distance - 1] = ft_strdup(farm->endRoom);
        path->roomsInPath[0] = ft_strdup(farm->startRoom);
        return path;
    }
}