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

t_path         *popPath(t_path **allPaths)// a path will be something like [1]-[3]-[5]-[2]-[4]
{
    t_path *poppedPath;

    poppedPath = *allPaths;//we then put the path [1]-[3]-[5]-[2]-[4] in poppedPath, now allPaths is empty.
    *allPaths = poppedPath->next;//allPaths now has the following paths [3]-[5]-[2]-[4]
    poppedPath->next = NULL;//[1]-NULL
    return (poppedPath);
}

static void     pushPath(t_path **allPaths, t_path *pushedPath)
{
    if (*allPaths == NULL)
        *allPaths = pushedPath;
    else 
    {
        pushedPath->next = *allPaths;
        *allPaths = pushedPath;
    }
}

void    sortPath(t_path **allPaths)
{
    t_path *holder;
    t_path *sortedPaths;

    holder = NULL;
    sortedPaths = NULL;
    while (*allPaths != NULL)
    {
        holder = popPath(allPaths);
        while (holder != NULL) //while we havent placed this path in its rightful placed, i.e while we still hold him
        {
            if (sortedPaths == NULL || (holder->distance <= sortedPaths->distance))
            {
                pushPath(&sortedPaths, holder);
                holder = NULL; 
            }
            else
                pushPath(allPaths, popPath(&sortedPaths));//we pop from sorted before pushing onto allPATHS
        }
    }
    *allPaths = sortedPaths;
}

void        addPathToPaths(t_path **allPaths, t_path * aPath)//we take in a double pointer because the stucture might change
{
    if (*allPaths == NULL)
        *allPaths  = aPath;
    else
    {
        aPath->next = *allPaths;
        *allPaths = aPath;
    }
}

void        getPaths(t_antFarm *farm)
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
    sortPath(&farm->allPaths);
    clearPaths(&farm->allPaths);
}