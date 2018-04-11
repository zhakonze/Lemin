/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*void    cleanPaths(t_path *allPaths) 
{

}

void    sortPath(t_path *allPaths)
{

}*/

void    addPathToPaths(t_path **allPaths, t_path * aPath)
{
    if (*allPaths == NULL)
        *allPaths  = aPath;
    else
    {
        aPath->next = *allPaths;
        *allPaths = aPath;
    }
}

void    getPaths(t_antFarm *farm)
{
    int     index;
    int     revIndex;
    t_room  *neighbour;
    t_path  *new_path;
    t_room  *endRoom;

    endRoom = getRoomFromFarm(farm, farm->endRoom);
    index = 0;
    while (endRoom->linked[index] != NULL)
    {
        neighbour = getRoomFromFarm(farm, endRoom->linked[index]);
        revIndex = neighbour->lvl;
        new_path = createPath(farm, neighbour->lvl + 2);
        while (revIndex > 0)
        {
            new_path->roomsInPath[revIndex] = ft_strdup(neighbour->name);
            neighbour = getRoomFromFarm(farm, neighbour->visitedBy);
            revIndex--;
        }
        addPathToPaths(&farm->allPaths, new_path);//& shows we change the structutre of that parameter, so we pass its address
        index++;
    }
}