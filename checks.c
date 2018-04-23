/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/* This function will check if the read line is a comment,
a comment will start with a '#' followed by anything else
other than a '#', if the line is a comment it returns '1'
else it returns '0'*/
int         isComment(char *line)
{

    if (ft_strlen(line) >= 1 && line[0] == '#' && line[1] != '#')
        return (1);
    else
        return (0);
}

/* This function will check if the read line is a command,
a command will start with a '#' followed by another '#',
if the line is a command it returns '1'
else it returns '0'*/
int         isCommand(char *line, t_antFarm *farm)
{
    char    *cmd;
    int     result;

    result = 1;
    if (ft_strlen(line) >= 2 && line[0] == '#' && line[1] == '#')
    {
        cmd = ft_strsub(line, 2, ft_strlen(line) - 2);//this is just to cut of the twwo #s
        if (ft_strequ(cmd, "end") == 1 || ft_strequ(cmd, "start") == 1)
            result = verifyRoomBeneath(farm, line, cmd, result);//this function will check if the line below the command is an actual room that has not been created yet. if the the next line is not a valid room, it will return 0, else it will return 1 then assign this rooms name to the farm's start or endRoom attribute based on the command
        free(cmd);
        cmd = NULL;
    }
    else
        result = 0;
    return (result);
}

/* This function will check if the line read is a room,
a room will have three digits separated by a spaces, the
first digit is the room number and the other two are co-ordinates.
We string-split the line to get the individual digits and store
them in a double pointer array, we then loop through the array to
check if we get three digits, if not then this is not a room.
We then also have to make sure that the components are infact numbers

getRoomFromFarm function will return NULL when the room does no
exist in the farm and will return the room if it exists*/

int         isRoom(char *line, t_antFarm *farm)
{
    char    **array;
    int     components;
    int     result;

    result = 1;
    if (farm->numAnts >= 0)
    {
        array = ft_strsplit(line, ' ');
        components = 0;
        while (array[components] != NULL)
            components++;
        if (components != 3)
            result = 0;
        if (result && ft_isnumber(array[1]) == 1 && ft_isnumber(array[2]) == 1)
        {
            if (getRoomFromFarm(farm, array[0]) != NULL)
                result = 0;
        }
        array = (char**)ft_clear_2d((void**)array);
    }
    else
        result = 0;
    return (result);
}

/* This function will check if the line read is a link,
a link will have two digits separated by a dash, the
a link can not have two identical numbers e.g 1-1(so room 1 can't be linked to room 1).
We string-split the line to get the individual digits and store
them in a double pointer array, we then loop through the array to
check if we get two digits, if not then this is not a link.
We then also have to make sure that the components are infact numbers */

int         isLink(char *line, t_antFarm *farm)
{
    char    **array;
    int     components;
    int     result;

    result = 1;
    if (farm->allRooms != NULL && farm->startRoom && farm->endRoom)//checks if we have rooms and if we have both start and end room. if this is false then we go to the else down there
    {
        array = ft_strsplit(line, '-');
        components = 0;
        while (array[components] != NULL)
            components++;
        if (components != 2 || (ft_strequ(array[0], array[1]) == 1))
            result = 0;
        if (result && (getRoomFromFarm(farm, array[0]) == NULL || //a link can only happen if a room was already created
            getRoomFromFarm(farm, array[1]) == NULL)) //so if getRoomFromFarm returns NULL that means then room was not set
            result = 0;
        array = (char**)ft_clear_2d((void**)array);
    }
    else
        result = 0;
    return (result);
}

int         isNumAnts(char *line, t_antFarm *farm)
{
    if (ft_isnumber(line))
    {
        if (farm->numAnts >= 0)
            return (-1);//here is if its a number but we've already read a number. in this case its an error. we exit program
        else
            return (1);
    }
    else
        return (0);//its only when the line is not a  number

}