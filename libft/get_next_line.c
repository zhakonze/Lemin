/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 09:48:43 by zhakonze          #+#    #+#             */
/*   Updated: 2017/07/13 15:09:22 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# define BUFF_SIZE 5

static int	copy_contents(const int fd, char **container)
{
	char	*buff;
	char	*tmp;
	int		chars_read;

	buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (buff == NULL)
		return (-1);
	chars_read = read(fd, buff, BUFF_SIZE);
	if (chars_read > 0)
	{
		buff[chars_read] = '\0';
		tmp = ft_strjoin(*container, buff);
		free(*container);
		*container = tmp;
	}
	free(buff);
	return (chars_read);
}

static int	holder_and_pre_check(char **h, const int fd, char **eol, int *cr)
{
	int		rtn_val;

	if (*h == NULL)
	{
		*h = (char*)malloc(sizeof(char));
		*h[0] = '\0';
	}
	if (*h == NULL || fd < 0 || BUFF_SIZE < 0)
		rtn_val = -1;
	else
		rtn_val = 1;
	*eol = ft_strchr(*h, '\n');
	if (*eol != NULL)
		*cr = 2;
	return (rtn_val);
}

static void	pro_strjoin(char **holder, char *str1, char *str2)
{
	char	*tmp;

	tmp = *holder;
	*holder = ft_strjoin(str1, str2);
	free(tmp);
}

static void	pro_strdup(char **holder, char *str1)
{
	char	*tmp;

	tmp = *holder;
	*holder = ft_strdup(str1);
	free(tmp);
}

int			get_next_line(const int fd, char **line)
{
	static char	*holder = NULL;
	char		*end_of_line;
	int			chars_read;

	if (holder_and_pre_check(&holder, fd, &end_of_line, &chars_read) == -1)
		return (-1);
	while (end_of_line == NULL)
	{
		chars_read = copy_contents(fd, &holder);
		if (chars_read == 0)
		{
			if (ft_strlen(holder) == 0)
				return (0);
			pro_strjoin(&holder, holder, "\n");
			end_of_line = ft_strchr(holder, '\n');
		}
		else if (chars_read < 0)
			return (-1);
		else
			end_of_line = ft_strchr(holder, '\n');
	}
	*line = ft_strsub(holder, 0, ft_strlen(holder) - ft_strlen(end_of_line));
	pro_strdup(&holder, &(end_of_line[1]));
	return (1);
}
