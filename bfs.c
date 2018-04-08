/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void        bfsSetup(t_antFarm  *farm)
{
    t_queue *queue;
    t_room  *startRoom;

    queue = NULL;
    startRoom = getRoomFromFarm(farm, farm->startRoom);
    startRoom->visited = 1;
    startRoom->visitedBy = startRoom->name;
    addToQueue(&queue, startRoom->name);
    bfs(farm, &queue);
    cleanUnvisited(farm);
}

void        bfs(t_antFarm *farm, t_queue **queue)
{
    int     index;
    t_room  *head;
    t_room  *neighbour;

    while(*queue != NULL)
    {
        head = getRoomFromFarm(farm, (*queue)->name);
        index = -1;
        while(head->linked[++index] != NULL)
        {
            neighbour = getRoomFromFarm(farm, head->linked[index]);
                if (ft_strequ(head->visitedBy, neighbour->name) == 1)
                    continue;//allows us to skip a neighbour who is the fathe i.e the visitor
                if (neighbour->visited == 1)
                {
                    clearLink(head->name, neighbour->name, farm);
                    index--;
                }
                else
                {
                    neighbour->visited = 1;
                    neighbour->visitedBy = ft_strdup(head->name);
                    neighbour->lvl = head->lvl + 1;
                    if (neighbour->lvl == 2)
                        neighbour->pathMaster = ft_strdup(head->name);
                    else if (neighbour->lvl > 2)
                        neighbour->pathMaster = ft_strdup(head->pathMaster);
                    addToQueue(queue, neighbour->name);
                }
        }
        removeFromQueue(queue);
    }
}

static char **removeNeighbour(char **linked, char *name)
{
    int     len;
    int     tmpIndex;
    int     linkedIndex;
    char    **tmpLinked;

    len = 0;
    tmpIndex = 0;
    linkedIndex = 0;
    while (linked[len] != NULL)
        len++;
    if ((tmpLinked = (char**)malloc(sizeof(char*)*((len - 1) + 1))) == NULL)//checking if we could allocate mem successfully
        return (NULL); //we return NULL if not allocated successfully
    tmpLinked[len - 1] = NULL; //NULL shifts to the prev len minus one because we're about to remove a link
    while (tmpIndex < len - 1)
    {
        if (ft_strequ(linked[linkedIndex], name) == 1)
            linkedIndex++;
        else
            tmpLinked[tmpIndex++] = ft_strdup(linked[linkedIndex++]);
    }
    linked = (char**)ft_clear_2d((void**)linked);
    return (tmpLinked);
}

void        clearLink(char *name1, char *name2, t_antFarm *farm) 
{
    t_room  *r1;
    t_room  *r2;

    r1 = getRoomFromFarm(farm, name1);
    r2 = getRoomFromFarm(farm, name2);

    //we need to remove r2 fro  r1's linked neighbours
    //and similarly we remove r1 from r2's neighbours

    r1->linked = removeNeighbour(r1->linked, name2);
    r2->linked = removeNeighbour(r2->linked, name1);
}

void     cleanUnvisited(t_antFarm *farm)
{
    int     index;
    int     linkIndex;
    t_room  *room;

    index = 0;
    linkIndex = 0;
    room = farm->allRooms;
    while (room != NULL)
    {
        if (room->visited == 0)
        {
            while (room->linked[linkIndex] != NULL)//this loop clears the link between this unvisited room and the rooms its linked to
                clearLink(room->name, room->linked[linkIndex], farm);
            //note that in this loop we dont increase linkIndex, this is because we want to always remove the one at the front i.e index 0
        }
        room = room->next;//continues to check all rooms in the farm
    }
}