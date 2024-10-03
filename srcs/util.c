#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_number.h"

char *get_suffix(t_num_data *data, int length)
{
    int i = 0;
    while (data[i].book_mark == MID)
    {
        if (data[i].length_number == length)
        {
            return data[i].numeral;
        }
        i++;
    }
    return (NULL);
}

char *str_join(char *src1, char *src2)
{
    int size = strlen(src1) + strlen(src2) + 2;
    char *result = calloc(size, sizeof(char));
    int i = 0, j = 0;
    while (i < size && *(src1 + i))
    {
        result[i] = src1[i];
        i++;
    }
    result[i] = 32;
    i++;
    while (i < size && *(src2 + j))
    {
        result[i] = src2[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return result;
}