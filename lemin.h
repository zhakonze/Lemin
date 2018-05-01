/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2018/05/01 10:37:36 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"

typedef struct		s_queue
{
	char			*name;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_path
{
	int				distance;
	char			**roomsinpath;
	struct s_path	*next;
}					t_path;

typedef struct		s_room
{
	char			*name;
	char			*visitedby;
	char			*pathmaster;
	int				visited;
	int				lvl;
	char			**linked;
	struct s_room	*next;
}					t_room;

typedef struct		s_ant
{
	int				antnum;
	int				pathnumber;
	t_path			*pathtravelthru;
	int				distancecovered;
	int				turntomove;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_antfarm
{
	int				numants;
	char			*startroom;
	char			*endroom;
	t_path			*allpaths;
	t_room			*allrooms;
	t_ant			*allants;
}					t_antfarm;

int					iscomment(char *line);
int					iscommand(char *line, t_antfarm *farm);
int					isroom(char *line, t_antfarm *farm);
int					islink(char *line, t_antfarm *farm);
void				addlink(t_room **room, char *name);
int					isnumants(char *line, t_antfarm *farm);
int					verifyroomdown(t_antfarm *f, char *l, char *c, int res);
int					createfarm(t_antfarm *farm, char *line, int result);
int					createroom(t_antfarm *farm, char *line);
int					createlink(t_antfarm *farm, char *line);
int					createants(t_antfarm *farm);
t_path				*createpath(t_antfarm *farm, int distance);
void				destroylinks(t_antfarm *farm);
void				destroyrooms(t_antfarm *farm);
void				destroypaths(t_antfarm *farm);
void				destroyants(t_antfarm *farm);
void				destroyfarm(t_antfarm *farm);
void				clearlink(char *name1, char *name2, t_antfarm *farm);
void				cleanunvisited(t_antfarm *farm);
void				bfssetup(t_antfarm	*farm);
void				moveants(t_antfarm *farm);
void				updateants(t_antfarm *farm, int numpaths);
void				cleanpaths(t_antfarm *farm);
t_queue				*createqueueitem(char *name);
void				getpath(t_antfarm *farm);
void				bfs(t_antfarm *farm, t_queue **queue);
void				removefromqueue(t_queue **queue);
void				addtoqueue(t_queue **queue, char *item);
t_room				*getroomfromfarm(t_antfarm *farm, char *room);
void				setvisitation(t_room *n, t_room *he, t_queue **q);
void				getpaths(t_antfarm *farm);
void				addpathtopaths(t_path **allpaths, t_path *apath);
void				sortpath(t_path **allpaths);
t_path				*poppath(t_path **allpaths);
void				destroyapath(t_path **allpaths);
void				clearpaths(t_path **allpaths);
int					getnumberofpaths(int ants, t_path *allpaths);
void				moveants(t_antfarm *farm);

#endif
