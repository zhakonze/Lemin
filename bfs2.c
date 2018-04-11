#include "lemin.h"


void    setVisitation(t_room *neigh, t_room *head, t_queue **queue)
{
    neigh->visited = 1;
    neigh->visitedBy = ft_strdup(head->name);
    neigh->lvl = head->lvl + 1;
    if (neigh->lvl == 2)
        neigh->pathMaster = ft_strdup(head->name);
    else if (neigh->lvl > 2)
        neigh->pathMaster = ft_strdup(head->pathMaster);
    addToQueue(queue, neigh->name);
}