#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_number.h"

int main(int argc, char *argv[])
{
    char *input_number;
    char *directory_name;
    FILE *directory = NULL;

    if (argc == 2)
    {
        input_number = argv[1];
        directory_name = "numbers.dict";
        print_number(input_number, directory_name, directory);
    }
    else if (argc == 3)
    {
        directory_name = argv[2];
        input_number = argv[1];
        print_number(input_number, directory_name, directory);
    }
    else
    {
        printf("Error! Mismatch argument count!\n");
        return (0);
    }
    return (0);
}

void print_number(char *input_number, char *directory_name, FILE *directory)
{
    t_digit *number = loading_digits(input_number);
    t_num_data *data = loading_data(directory, directory_name);
    int length = strlen(input_number);
    char *result;
    if (length == 1)
    {
        result = single_digit(data, number);
        printf("%s\n", result);
    }
    if (length == 2)
    {
        result = double_digit(data, number);
        printf("%s\n", result);
    }
    free(result);
    free(number);
    free(data);
}

char *single_digit(t_num_data *data, t_digit *number)
{
    int i = 0;

    while (data[i].book_mark == MID)
    {
        if (number[0].nbr == data[i].number[0])
        {
            return (data[i].numeral);
        }
        i++;
    }
    return (NULL);
}

char *double_digit(t_num_data *data, t_digit *number)
{
    int i = 0, j = 0;
    char *str = calloc(1024, sizeof(char));

    while (data[i].book_mark == MID)
    {
        if (number[0].nbr == '0' && number[1].nbr == data[i].number[0])
        {
            str = strcpy(str, data[i].numeral);
            return str;
        }
        if (number[0].nbr == '1' && number[0].nbr == data[i].number[0] && number[1].nbr == data[i].number[1])
        {
            str = strcpy(str, data[i].numeral);
            return str;
        }
        if (number[1].nbr == '0' && number[0].nbr == data[i].number[0] && number[1].nbr == data[i].number[1])
        {
            str = strcpy(str, data[i].numeral);
            return str;
        }
        if (number[0].nbr != '1' && number[1].nbr != '0')
        {
            if (number[0].nbr == data[i].number[0] && data[i].number[1] == '0')
            {
                str = strcpy(str, data[i].numeral);
                str = strcat(str, " ");
                while (data[j].book_mark == MID)
                {
                    if (number[1].nbr == data[j].number[0])
                    {
                        str = strcat(str, data[j].numeral);
                        return str;
                    }
                    j++;
                }
            }
        }
        i++;
    }
    return (NULL);
}