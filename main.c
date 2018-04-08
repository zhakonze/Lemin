#include "lemin.h"

int main(void)
{
    t_antFarm   farm;
    char        *line;
    int         result;
    
    result = 1;
    line = NULL;
    farm = (t_antFarm) {-1, NULL, NULL, NULL, NULL, NULL};
    result = createFarm(&farm, line, result);
    if (result == 0)
    {
        ft_putendl("Error");
        exit(0);
    }
 //   createPaths(&farm);
    createAnts(&farm);
    printf("\nfarm contains : %d ants\n\n\t\tFarm before bfs\n\n", farm.numAnts);
    t_room *rooms = farm.allRooms;
    while (rooms != NULL)
    {
        printf("farm contains room : %s\n", rooms->name);
        int index = 0;
        while (rooms->linked[index])
        {
            printf("\t\tneighbour %d: %s\n", index + 1, rooms->linked[index]);
            index++;
        }
        rooms = rooms->next;
    }
    printf("\nstart room is : %s\nend room is   : %s\n\n\n\t\tFarm after bfs\n\n",farm.startRoom, farm.endRoom);
    bfsSetup(&farm);
    rooms = farm.allRooms;
    while (rooms != NULL)
    {
        printf("farm contains room : %s\n", rooms->name);
        int index = 0;
        while (rooms->linked[index])
        {
            printf("\t\tneighbour %d: %s\n", index + 1, rooms->linked[index]);
            index++;
        }
        rooms = rooms->next;
    }
   // moveAnts(&farm);
    //destroyFarm(&farm);    
    return (0);
}