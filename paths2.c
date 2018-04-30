/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2018/05/01 13:06:25 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		clearpaths(t_path **allpaths)
{
	t_path	*head;
	t_path	*afterhead;
	t_path	*holder;

	head = *allpaths;
	while (head != NULL)
	{
		afterhead = head->next;
		holder = head;
		while (afterhead != NULL)
		{
			if (ft_strequ(head->roomsinpath[1], afterhead->roomsinpath[1]) == 1)
			{
				destroyapath(&afterhead);
				holder->next = afterhead;
			}
			else
			{
				afterhead = afterhead->next;
				holder = holder->next;
			}
		}
		head = head->next;
	}
}

static int	getpathdistance(t_path *allpaths, int pathindex)
{
	t_path	*tmp;
	int		index;

	tmp = allpaths;
	index = 0;
	while (index < pathindex)
	{
		tmp = tmp->next;
		index++;
	}
	return (tmp->distance);
}

static int	getrounds(int numpaths, t_path *allpaths, int allants, int antsleft)
{
	int		max;
	int		round;
	int		pathdistance;
	int		path;
	int		antsinapath;

	max = -2147483647;
	path = 1;
	while (path <= numpaths)
	{
		if (antsleft != 0)
		{
			antsleft--;
			antsinapath = (int)(allants / numpaths) + 1;
		}
		else
			antsinapath = (int)(allants / numpaths);
		pathdistance = getpathdistance(allpaths, path - 1);
		round = antsinapath + pathdistance - 2;
		// printf("\n\t\t\t\t if %d travel though path %d, the rounds taken is:
		// 		%d\n", antsinapath, path, round);
		max = (round > max) ? round : max;
		path++;
	}
	return (max);
}

int			getnumberofpaths(int ants, t_path *allpaths)
{
	int		minrounds;
	int		rounds;
	int		result;
	int		numpaths;
	t_path	*tmppath;

	minrounds = 2147483647;
	tmppath = allpaths;
	numpaths = 1;
	while (tmppath != NULL)
	{
		rounds = getrounds(numpaths, allpaths, ants, ants % numpaths);
		// printf("\n\t\t\tthough %d paths, the final min rounds is: %d\n\n\n",
		// 		numpaths, rounds);
		if (rounds < minrounds)
		{
			minrounds = rounds;
			result = numpaths;
		}
		tmppath = tmppath->next;
		numpaths++;
	}
	return (result);
}
