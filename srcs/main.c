#include <stdio.h>
#include <stdlib.h>
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
    int i = 0, j = 0;
    while (number[i].book_mark != END)
    {
        printf("number : %c | index : %d | length : %d | book mark : %d \n", number[i].nbr, number[i].index, number[i].length, number[i].book_mark);
        i++;
    }
    printf("\n");
    while (data[j].book_mark != END)
    {
        printf("number : %s | numeral : %s | length : %d | book mark : %d \n", data[j].number, data[j].numeral, data[j].length_number, data[j].book_mark);
        j++;
    }
    printf("\n");
    free(number);
    free(data);
}