#include "lemin.h"

int main(void)
{
    t_antfarm   farm;
    char        *line;
    int         result;//shows if farm data is successfully read, i.e created, from the map..
    int         numPaths;

    result = 1;
    line = NULL;
    farm = (t_antfarm) {-1, NULL, NULL, NULL, NULL, NULL};// in the farm we can be given zero number of ants,so that means the the ants can range from 0-1000, so by me saying -1 just means no ants can be -1
    result = createfarm(&farm, line, result);
    if (result == 0)
    {
        ft_putendl("Error");
        exit(0);
    }
    //   createpaths(&farm);
    //createants(&farm);
    // printf("\nfarm contains : %d ants\n\n\t\tFarm before bfs\n\n", farm.numants);
    t_room *rooms = farm.allrooms;
    while (rooms != NULL)
    {
        // printf("farm contains room : %s\n", rooms->name);
        int index = 0;
        while (rooms->linked[index])
        {
            // printf("\t\tneighbour %d: %s\n", index + 1, rooms->linked[index]);
            index++;
        }
        rooms = rooms->next;
    }
    // printf("\nstart room is : %s\nend room is   : %s\n\n\n\t\tFarm after bfs\n\n",farm.startroom, farm.endroom);
    bfssetup(&farm);
    //this section prints the farm after bfs transformation
    rooms = farm.allrooms;
    // while (rooms != NULL)
    // {
    //     printf("farm contains room : %s\n", rooms->name);
    //     int index = 0;
    //     while (rooms->linked[index])
    //     {
    //         printf("\t\tneighbour %d: %s\n", index + 1, rooms->linked[index]);
    //         index++;
    //     }
    //     rooms = rooms->next;
    // }

    //this section is where we print out the paths we got after bfs
    // printf("\n\n\n These are the paths\n\n");
    getpaths(&farm);
    t_path *path;
    path = farm.allpaths;
    // int pathNum = 1;
    // while (path != NULL)
    // {
    //     int index = 0;
    //     printf("These are the rooms in path %d\n", pathNum);
    //     while (path->roomsinpath[index] != NULL)
    //     {
    //         printf("\t\troom%d: %s\n", index + 1, path->roomsinpath[index]);
    //         index++;
    //     }
    //     pathNum++;
    //     path = path->next;
    // }

    //this section is best path number section
    numPaths = getnumberofpaths(farm.numants, farm.allpaths);
    // printf("\n\n\n The best number of paths to use.\n\n\t\t-:\t%d\n", numPaths);


    //this section is the ant details;
    updateants(&farm, numPaths);
    // printf("\n\n\n The ant's info is as follows.\n\n");
    t_ant *ant = farm.allants;
    int  antnum = 1;
    while (ant != NULL)
    {
        // printf("\t\t ant %d details :\n", antnum);
        antnum++;
        // printf("\t\t\t path number : %d\n\t\t\t distance : %d\n\t\t\t turn : %d\n\n",ant->pathnumber , ant->distancecovered, ant->turntomove);
        ant = ant->next;
    }

    //finally moving the ants
    printf("\n\n\n Ant movement\n\n");
    moveants(&farm);
    //destroyFarm(&farm);    
    return (0);
}