/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void        clearPaths(t_path **allPaths)
{
    t_path *head;
    t_path *afterHead;
    t_path *holder;

    head = *allPaths;
    while (head != NULL)
    {
        afterHead = head->next;
        holder = head;
        while (afterHead != NULL)
        {
            if (ft_strequ(head->roomsInPath[1], afterHead->roomsInPath[1]) == 1)
            {
                destroyAPath(&afterHead);
                holder->next = afterHead;
            }
            else
            {
                afterHead = afterHead->next;
                holder = holder->next;
            }
        }
        head = head->next;
    }
}

static int  getPathDistance(t_path *allPaths, int pathIndex)
{
    t_path  *tmp;
    int     index;

    tmp = allPaths;
    index = 0;
    while (index < pathIndex)
    {
        tmp = tmp->next;
        index++;
    }
    return(tmp->distance);
}

static int  getRounds(int numPaths, t_path *allPaths, int allAnts, int remainingAnts)
{
    int     max;
    int     round;
    int     pathDistance;
    int     path;
    int     antsInAPath;

    max = -2147483647;
    path = 1;
    while (path <= numPaths)
    {
        if (remainingAnts != 0)
        {
            remainingAnts--;
            antsInAPath = (int)(allAnts / numPaths) + 1;
        }
        else
            antsInAPath = (int)(allAnts / numPaths);
        pathDistance = getPathDistance(allPaths, path - 1);
        round = antsInAPath + pathDistance - 2;
        printf("\n\t\t\t\t if %d travel though path %d , the rounds taken is: %d\n",antsInAPath,path,round);
        max = (round > max)? round : max;
        path++;    
    }
    return (max);
}

int         getNumberOfPaths(int ants, t_path *allPaths)
{
    int     minRounds;
    int     rounds;
    int     result;
    int     numPaths;
    t_path  *tmpPath;

    minRounds = 2147483647;
    tmpPath = allPaths;
    numPaths = 1;
    while(tmpPath != NULL)
    {
        rounds = getRounds(numPaths, allPaths, ants, ants % numPaths);
        printf("\n\t\t\tthough %d paths, the final min rounds is: %d\n\n\n",numPaths, rounds);
        if (rounds < minRounds)
        {
            minRounds = rounds;
            result = numPaths;
        }
        tmpPath = tmpPath->next;
        numPaths++;
    }
    return (result);
}