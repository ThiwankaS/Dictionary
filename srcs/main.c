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
    char *number = loading_digits(input_number);
    t_num_data *data = loading_data(directory, directory_name);
    int length = strlen(input_number);
    char *result;
    if (length == 1)
    {
        result = single_digit(data, number, 0);
        printf("%s\n", result);
    }
    if (length == 2)
    {
        result = double_digit(data, number, 1);
        printf("%s\n", result);
    }
    if (length == 3)
    {
        result = triple_digit(data, number, 2);
        printf("%s\n", result);
    }

    free(result);
    free(number);
    free(data);
}

char *single_digit(t_num_data *data, char *number, int index)
{
    int i = 0;

    while (data[i].book_mark == MID)
    {
        if (number[index] == data[i].number[0])
        {
            return (data[i].numeral);
        }
        i++;
    }
    return (NULL);
}

char *double_digit(t_num_data *data, char *number, int index)
{
    int i = 0, j = 0;
    char *str = calloc(1024, sizeof(char));

    while (data[i].book_mark == MID)
    {
        // For all the other numbers XX excluding above paterns
        if (number[index - 1] != '1' && number[index] != '0')
        {
            if (number[index - 1] == data[i].number[0] && data[i].number[1] == '0')
            {
                str = strcpy(str, data[i].numeral);
                str = strcat(str, " ");
                while (data[j].book_mark == MID)
                {
                    if (number[index] == data[j].number[0])
                    {
                        str = strcat(str, data[j].numeral);
                        return str;
                    }
                    j++;
                }
            }
        }
        // For numbers X0 excluding 10
        if (number[index] == '0' && number[index - 1] != '1' && number[index - 1] == data[i].number[0] && number[index] == data[i].number[1])
        {
            str = strcpy(str, data[i].numeral);
            return str;
        }
        // For numbers 1X
        if (number[index - 1] == '1' && number[index - 1] == data[i].number[0] && number[index] == data[i].number[1])
        {
            str = strcpy(str, data[i].numeral);
            return str;
        }
        // For numbers 0X
        if (number[index - 1] == '0' && number[index] == data[i].number[0])
        {
            str = strcpy(str, data[i].numeral);
            return str;
        }
        i++;
    }
    return (NULL);
}

char *triple_digit(t_num_data *data, char *number, int index)
{
    char *str = calloc(1024, sizeof(char));
    if (number[0] == '0')
    {
        if (number[1] == '0')
        {
            str = strcpy(str, single_digit(data, number, index));
            return (str);
        }
        str = strcpy(str, double_digit(data, number, index));
        return (str);
    }
    else
    {
        int i = 0;
        while (data[i].book_mark == MID)
        {
            if (number[0] == data[i].number[0] && data[i].length_number == 1)
            {
                str = strcpy(str, data[i].numeral);
            }
            i++;
        }
        str = strcat(str, " ");
        str = strcat(str, get_suffix(data, 3));
        if (number[1] != '0' && number[2] != '0')
        {
            str = strcat(str, " ");
            str = strcat(str, double_digit(data, number, 2));
        }
        return (str);
    }
    return (NULL);
}

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