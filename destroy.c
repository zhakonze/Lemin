/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
/*
void        destroyLinks(t_antFarm *farm)
{

}

void        destroyRooms(t_antFarm *farm)
{
}
*/

void        destroyAPath(t_path **allPaths)
{
    t_path *head;

    head = popPath(allPaths);
    head->roomsInPath = (char**)ft_clear_2d((void**)head->roomsInPath);
    free(head);
}
/*
void        destroyAnts(t_antFarm *farm)
{

}

void        destroyFarm(t_antFarm *farm)
{
    
}*/