/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths2.c                                            :+:      :+:    :+:   */
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