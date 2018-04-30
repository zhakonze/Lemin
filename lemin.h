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
    char            *name;//name of unvisted rooms
    struct s_queue  *next;//this means we gonna have a linked-list of all unvisited rooms
}                   t_queue;

typedef struct      s_path
{
    int             distance;
    char            **roomsInPath;
    struct s_path   *next;//this means we gonna have a linked-list of all paths
}                   t_path;

typedef struct      s_room
{
    char            *name;//actual name of the room.
    char            *visitedBy;//this just tells us which room the room is visited by.
    char            *pathMaster;//shows a room can only belong to one path. a pathmaster is one of the kids of the startroom because any path from the start must go through one of these kids
    int             visited;//this will be used to mark if the room has been visted or not
    int             lvl;//this will tell us the how far the room is from the start.
    char            **linked;//this is an array of names. the names are the rooms this one is linked to.
    struct s_room   *next;
}                   t_room;

typedef struct      s_ant
{
    int             antnum;
    int             pathNumber;
    t_path          *pathtravelthru;//an ant can only travel thru one path, so an ant needs to know which path its going to travel thru.
    int             distancecovered;//distance an ant has travelled so we know if it has reached the end of the path.
    int             turntomove;//all ants can't move at once, so this will instruct the ant if its turn to move
    struct s_ant    *next;
}                   t_ant;

typedef struct      s_antFarm
{
    int             numants;
    char            *startroom;
    char            *endRoom;
    t_path          *allPaths;//after bfs
    t_room          *allRooms;
    t_ant           *allants;
}                   t_antfarm;

int                 iscomment(char *line);
int                 iscommand(char *line, t_antfarm *farm);
int                 isroom(char *line, t_antfarm *farm);
int                 islink(char *line, t_antfarm *farm);
void                addLink(t_room **room, char *name);
int                 isnumants(char *line, t_antfarm *farm);
int                 verifyroombeneath(t_antfarm *f, char *l, char *c, int res);
int                 createfarm(t_antfarm *farm, char *line, int result);
int                 createroom(t_antfarm *farm, char *line);
int                 createlink(t_antfarm *farm, char *line);
int                 createants(t_antfarm *farm);
t_path              *createpath(t_antfarm *farm, int distance);
void                destroyLinks(t_antfarm *farm);
void                destroyRooms(t_antfarm *farm);
void                destroyPaths(t_antfarm *farm);
void                destroyAnts(t_antfarm *farm);
void                destroyFarm(t_antfarm *farm);
void                clearlink(char *name1, char *name2, t_antfarm *farm);
void                cleanunvisited(t_antfarm *farm);
void                bfssetup(t_antfarm  *farm);
void                moveAnts(t_antfarm *farm);
void                updateants(t_antfarm *farm, int numPaths);
void                cleanPaths(t_antfarm *farm);
t_queue             *createQueueItem(char *name);
void                getPath(t_antfarm *farm);
void                bfs(t_antfarm *farm, t_queue **queue);
void                removeFromQueue(t_queue **queue);
void                addToQueue(t_queue **queue, char *item);
t_room              *getroomfromfarm(t_antfarm *farm, char *room);
void                setvisitation(t_room *n, t_room *he, t_queue **q);
void                getPaths(t_antfarm *farm);
void                addPathToPaths(t_path **allPaths, t_path * aPath);
void                sortPath(t_path **allPaths);
t_path              *popPath(t_path **allPaths);
void                destroyapath(t_path **allPaths);
void                clearPaths(t_path **allPaths);
int                 getNumberOfPaths(int ants, t_path *allPaths);
void                moveants(t_antfarm *farm);





#endif