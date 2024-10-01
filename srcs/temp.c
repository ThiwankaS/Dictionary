#include <stdio.h>
#include <stdlib.h>
#include "ft_number.h"

t_num_data *open_directory(FILE *directory, char *directory_name);
void print_number(FILE *directory, char *directory_name, char *input_number);

int main(int argc, char *argv[])
{
    char *input_number;
    char *directory_name;
    FILE *directory = NULL;

    if (argc == 2)
    {
        input_number = argv[1];
        directory_name = "numbers.dict";
        print_number(directory, directory_name, input_number);
    }
    else if (argc == 3)
    {
        directory_name = argv[2];
        input_number = argv[1];
        print_number(directory, directory_name, input_number);
    }
    else
    {
        printf("Error! Mismatch argument count!\n");
        return (0);
    }
    return (0);
}

t_num_data *open_directory(FILE *directory, char *directory_name)
{
    t_num_data *data;

    directory = fopen(directory_name, "r+");
    if (!directory)
    {
        return ((t_num_data *)0);
    }
    data = loading_data(directory, directory_name);
    return (data);
}

void print_number(FILE *directory, char *directory_name, char *input_number)
{
    t_num_data *data;
    t_digit *digits;
    char *result = NULL;

    data = open_directory(directory, directory_name);
    digits = loading_digits(input_number);
    result = final_numeral(data, digits, result);
}

char *final_numeral(t_num_data *data, t_digit *digits, char *result)
{
    char *str1 = NULL;
    if (digits[0].length > 3)
    {
    }
    str1 = three_digit_number(data, digits, str1);

    return (str1);
}

char *three_digit_number(t_num_data *data, t_digit *digits, char *result)
{
    int i = 0;
    char *str1 = NULL;
    char *str2;
    char *str3;
    char *str4;

    while ((digits[i].length - i) > 0)
    {
        if ((digits[i].length - i) == 1)
        {
            str4 = get_last_digit(data, digits, digits[i].nbr, &i);
        }
        if ((digits[i].length - i) == 2)
        {
            str3 = get_two_digit(data, digits, digits[i].nbr, &i);
        }
        if (digits[i].length - i > 2)
        {
            str1 = get_prefix(data, digits[i].nbr, digits[i].length - i);
            str2 = get_range(data, digits[i].nbr, digits[i].length - i);
            printf("%s\n", str1);
            printf("%s\n", str2);
        }
        i++;
    }
    return (str1);
}