/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antUpdates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	updateants(t_antfarm *farm, int numPaths)
{
	t_ant	*tmpAnt;
	t_path	*path;
	int		index;

	createants(farm);
	tmpAnt = farm->allants;
	while (tmpAnt != NULL)
	{
		tmpAnt->distancecovered = 1;
		if (tmpAnt->antnum % numPaths == 0)
		{
			tmpAnt->pathNumber = numPaths;
			tmpAnt->turntomove = tmpAnt->antnum / numPaths;
		}
		else
		{
			tmpAnt->pathNumber = tmpAnt->antnum % numPaths;
			tmpAnt->turntomove = (int)(tmpAnt->antnum / numPaths) + 1;
		}
		path = farm->allPaths;
		index = 0;
		while (++index != tmpAnt->pathNumber)
			path = path->next;
		tmpAnt->pathtravelthru = path;
		tmpAnt = tmpAnt->next;
	}
}