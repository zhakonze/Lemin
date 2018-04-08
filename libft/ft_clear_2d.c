#include "libft.h"

void        **ft_clear_2d(void **array)
{
    int index;

    index = 0;
    while (array[index])
    {
        free(array[index]);
        array[index] = NULL;
        index++;
    }
    free(array);
    array = NULL;
    return (array);
}
