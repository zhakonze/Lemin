/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */    

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"

typedef struct      s_queue
{
    char            *name;
    struct s_queue  *next;
}                   t_queue;

typedef struct      s_path
{
    int             distance;
    char            **roomsInPath;
    struct s_path   *next;
}                   t_path;

typedef struct      s_room
{
    char            *name;
    char            *visitedBy;
    char            *pathMaster;
    int             visited;
    int             lvl;
    char            **linked;//this is an array of names. the names are the rooms this one is linked to.
    struct s_room   *next;
}                   t_room;

typedef struct      s_ant
{
    int             antNum;
    t_path          *pathTravelThru;
    int             distanceCovered;
    int             turnToMove;
    struct s_ant    *next;
}                   t_ant;

typedef struct      s_antFarm
{
    int             numAnts;
    char            *startRoom;
    char            *endRoom;
    t_path          *allPaths;
    t_room          *allRooms;
    t_ant           *allAnts;
}                   t_antFarm;

int                 isComment(char *line);
int                 isCommand(char *line, t_antFarm *farm);
int                 isRoom(char *line, t_antFarm *farm);
int                 isLink(char *line, t_antFarm *farm);
void                addLink(t_room **room, char *name);
int                 isNumAnts(char *line, t_antFarm *farm);
int                 verifyRoomBeneath(t_antFarm *f, char *l, char *c, int res);
int                 createFarm(t_antFarm *farm, char *line, int result);
int                 createRoom(t_antFarm *farm, char *line);
int                 createLink(t_antFarm *farm, char *line);
int                 createAnts(t_antFarm *farm);
t_path              *createPath(t_antFarm *farm, int distance);
void                destroyLinks(t_antFarm *farm);
void                destroyRooms(t_antFarm *farm);
void                destroyPaths(t_antFarm *farm);
void                destroyAnts(t_antFarm *farm);
void                destroyFarm(t_antFarm *farm);
void                clearLink(char *name1, char *name2, t_antFarm *farm);
void                cleanUnvisited(t_antFarm *farm);
void                bfsSetup(t_antFarm  *farm);
void                moveAnts(t_antFarm *farm);
void                sortPaths(t_antFarm *farm);
void                cleanPaths(t_antFarm *farm);
t_queue             *createQueueItem(char *name);
void                getPath(t_antFarm *farm);
void                bfs(t_antFarm *farm, t_queue **queue);
void                removeFromQueue(t_queue **queue);
void                addToQueue(t_queue **queue, char *item);
void                sortPath(t_path *allPaths);
t_room              *getRoomFromFarm(t_antFarm *farm, char *room);
void                setVisitation(t_room *n, t_room *he, t_queue **q);
void                getPaths(t_antFarm *farm);
void                addPathToPaths(t_path **allPaths, t_path * aPath);






#endif