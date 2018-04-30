/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2018/05/01 11:02:02 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			verifyroomdown(t_antfarm *farm, char *line, char *cmd, int result)
{
	char	**split;

	get_next_line(0, &line);
	line = ft_strtrim(line);
	if (isroom(line, farm) == 1)
	{
		split = ft_strsplit(line, ' ');
		createroom(farm, line);
		if (ft_strequ(cmd, "end") == 1 && farm->endroom == NULL)
			farm->endroom = ft_strdup(split[0]);
		else if (ft_strequ(cmd, "start") == 1 && farm->startroom == NULL)
			farm->startroom = ft_strdup(split[0]);
		else
			result = 0;
		split = (char**)ft_clear_2d((void**)split);
	}
	else
		result = 0;
	if (result)
		ft_putendl(line);
	return (result);
}

void		addlink(t_room **room, char *name)
{
	int		len;
	int		index;
	char	**templinked;

	len = 0;
	index = 0;
	if ((*room)->linked == NULL)
	{
		(*room)->linked = (char**)malloc(sizeof(char*) * 2);
		(*room)->linked[0] = ft_strdup(name);
		(*room)->linked[1] = NULL;
	}
	else
	{
		while ((*room)->linked[len] != NULL)
			len++;
		len++;
		templinked = (char**)malloc(sizeof(char*) * (len + 1));
		while ((*room)->linked[index] != NULL)
		{
			templinked[index] = (*room)->linked[index];
			index++;
		}
		templinked[index] = ft_strdup(name);
		templinked[index + 1] = NULL;
		(*room)->linked = templinked;
	}
}
