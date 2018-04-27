#include "lemin.h"

int main(void)
{
    t_antFarm   farm;
    char        *line;
    int         result;//shows if farm data is successfully read, i.e created, from the map..

    result = 1;
    line = NULL;
    farm = (t_antFarm) {-1, NULL, NULL, NULL, NULL, NULL};// in the farm we can be given zero number of ants,so that means the the ants can range from 0-1000, so by me saying -1 just means no ants can be -1
    result = createFarm(&farm, line, result);
    if (result == 0)
    {
        ft_putendl("Error");
        exit(0);
    }
    //   createPaths(&farm);
    //createAnts(&farm);
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
    //this section prints the farm after bfs transformation
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

    //this section is where we print out the paths we got after bfs
    printf("\n\n\n These are the paths\n\n");
    getPaths(&farm);
    t_path *path;
    path = farm.allPaths;
    int pathNum = 1;
    while (path != NULL)
    {
        int index = 0;
        printf("These are the rooms in path %d\n", pathNum);
        while (path->roomsInPath[index] != NULL)
        {
            printf("\t\troom%d: %s\n", index + 1, path->roomsInPath[index]);
            index++;
        }
        pathNum++;
        path = path->next;
    }

    printf("\n\n\n The best number of paths to use.\n\n\t\t-:\t%d\n",getNumberOfPaths(farm.numAnts, farm.allPaths));


   // moveAnts(&farm);
    //destroyFarm(&farm);    
    return (0);
}