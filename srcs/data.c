#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ft_number.h"

char *ft_only_number(char *str)
{
    int count;
    int iterator;
    char *result;
    int size = strlen(str) + 1;

    count = 0;
    iterator = 0;
    result = (char *)calloc(size, sizeof(char));
    while (*(str + iterator))
    {
        if (isdigit(str[iterator]))
        {
            result[count] = str[iterator];
            count++;
        }
        iterator++;
    }
    str[iterator] = '\0';
    return (result);
}

char *ft_only_alpha(char *str)
{
    int count;
    int iterator;
    char *result;
    int size = strlen(str) + 1;

    count = 0;
    iterator = 0;
    result = (char *)calloc(size, sizeof(char));
    while (*(str + iterator))
    {
        if (isalpha(str[iterator]))
        {
            result[count] = str[iterator];
            count++;
        }
        iterator++;
    }
    result[iterator] = '\0';
    return (result);
}

t_num_data *loading_data(FILE *directory, char *directory_name)
{
    char number[40];
    char spelling[50];
    int iterator;
    t_num_data *data;

    directory = fopen(directory_name, "r+");

    if (!directory)
    {
        return ((t_num_data *)0);
    }

    iterator = 0;
    data = (t_num_data *)malloc((BUFFER_SIZE + 1) * sizeof(t_num_data));
    while (fscanf(directory, "%s %s", number, spelling) != EOF)
    {
        data[iterator].number = ft_only_number(number);
        data[iterator].numeral = ft_only_alpha(spelling);
        data[iterator].length_number = ft_strlen(data[iterator].number);
        data[iterator].book_mark = MID;
        iterator++;
    }
    data[iterator].book_mark = END;
    return (data);
}

int ft_strlen(char *str)
{
    int count = 0;
    while (*(str + count))
        count++;
    return count;
}