/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int         verifyroombeneath(t_antfarm *farm, char *line, char *cmd, int result)
{
    char    **split;

    get_next_line(0, &line);
    line = ft_strtrim(line);
    if (isroom(line, farm) == 1)
    {
        split = ft_strsplit(line, ' ');//we split bcos we need to retrieve the rooms name from the line we gnl gave us. its at index 0 in the array strsplit returns
        createroom(farm, line);// since we found that the line we read is valid, now we create that room and add it to the farm
        if (ft_strequ(cmd, "end") == 1 && farm->endRoom == NULL)
            farm->endRoom = ft_strdup(split[0]);//copies the rooms name to the farm's endRoom attribute. this is just to note down that the room just created is the endroom
        else if (ft_strequ(cmd, "start") == 1 && farm->startroom == NULL)
            farm->startroom = ft_strdup(split[0]);
        else
            result = 0;
        split = (char**)ft_clear_2d((void**)split); // we clear the mem strsplit allocated
    }
    else
        result = 0;//line beneath command is not a room
    if (result)
        ft_putendl(line);
    return (result);
}

void        addLink(t_room **room, char *name)
{
    int     len;
    int     index;
    char    **tempLinked;


    len = 0;
    index = 0;
    //annotation of double pointers is done by putting an * together with the original pointers name in brackets
    //i.e if we have t_room *r1, and we need to change it somehow, we pass its address to a func. (&r1)
    //this results in r1 becoming a double pointer in the func, **r1.
    //to access its attributes, we use this notation ===> (*r1)->name or something.
    //this applies only if we passed the address of a pointer to a function.

    if ((*room)->linked == NULL)//checks if we need to malloc 2d array of chars;
    {
        (*room)->linked = (char**)malloc(sizeof(char*)*2);
        (*room)->linked[0] = ft_strdup(name);
        (*room)->linked[1] = NULL;
    }
    else
    {
        while ((*room)->linked[len] != NULL)
            len++;
        len++;//before this the len will be the len of original, we add this one extra for the new temp
        tempLinked = (char**)malloc(sizeof(char*)*(len + 1));
        //the loop bellow copies from ori to tmp and stops at the null
        while ((*room)->linked[index] != NULL)
        {
            tempLinked[index] = (*room)->linked[index];
            index++;
        }
        //after stopping at null, we now copy the new neighbour in.
        tempLinked[index] = ft_strdup(name);

        tempLinked[index + 1] = NULL;
       // (*room)->linked = (char**)ft_clear_2d((void**)(*room)->linked);
        (*room)->linked = tempLinked;
    }
}