/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2018/04/27 11:29:29 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	setvisitation(t_room *neigh, t_room *head, t_queue **queue)
{
	neigh->visited = 1;
	neigh->visitedby = ft_strdup(head->name);
	neigh->lvl = head->lvl + 1;
	if (neigh->lvl == 2)
		neigh->pathmaster = ft_strdup(head->name);
	else if (neigh->lvl > 2)
		neigh->pathmaster = ft_strdup(head->pathmaster);
	addtoqueue(queue, neigh->name);
}
