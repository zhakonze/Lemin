/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2018/04/27 11:27:05 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			iscomment(char *line)
{
	if (ft_strlen(line) >= 1 && line[0] == '#' && line[1] != '#')
		return (1);
	else
		return (0);
}

int			iscommand(char *line, t_antfarm *farm)
{
	char	*cmd;
	int		result;

	result = 1;
	if (ft_strlen(line) >= 2 && line[0] == '#' && line[1] == '#')
	{
		cmd = ft_strsub(line, 2, ft_strlen(line) - 2);
		if (ft_strequ(cmd, "end") == 1 || ft_strequ(cmd, "start") == 1)
			result = verifyroombeneath(farm, line, cmd, result);
		free(cmd);
		cmd = NULL;
	}
	else
		result = 0;
	return (result);
}

int			isroom(char *line, t_antfarm *farm)
{
	char	**array;
	int		components;
	int		result;

	result = 1;
	if (farm->numants >= 0)
	{
		array = ft_strsplit(line, ' ');
		components = 0;
		while (array[components] != NULL)
			components++;
		if (components != 3)
			result = 0;
		if (result && ft_isnumber(array[1]) == 1 && ft_isnumber(array[2]) == 1)
		{
			if (getroomfromfarm(farm, array[0]) != NULL)
				result = 0;
		}
		array = (char**)ft_clear_2d((void**)array);
	}
	else
		result = 0;
	return (result);
}

int			islink(char *line, t_antfarm *farm)
{
	char	**array;
	int		components;
	int		result;

	result = 1;
	if (farm->allRooms != NULL && farm->startroom && farm->endRoom)
	{
		array = ft_strsplit(line, '-');
		components = 0;
		while (array[components] != NULL)
			components++;
		if (components != 2 || (ft_strequ(array[0], array[1]) == 1))
			result = 0;
		if (result && (getroomfromfarm(farm, array[0]) == NULL ||
					getroomfromfarm(farm, array[1]) == NULL))
			result = 0;
		array = (char**)ft_clear_2d((void**)array);
	}
	else
		result = 0;
	return (result);
}

int			isnumants(char *line, t_antfarm *farm)
{
	if (ft_isnumber(line))
	{
		if (farm->numants >= 0)
			return (-1);
		else
			return (1);
	}
	else
		return (0);
}
