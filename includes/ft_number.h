#ifndef FT_NUMBER_H
#define FT_NUMBER_H

#include <stdio.h>

#define END 0
#define MID 1
#define BUFFER_SIZE 41

typedef struct NumeralsData
{
    char *number;
    char *numeral;
    int length_number;
    int book_mark;
} t_num_data;

typedef struct Digit
{
    char nbr;
    int index;
    int length;
    int book_mark;
} t_digit;

char *ft_only_alpha(char *str);
char *ft_only_number(char *str);
char *single_digit(t_num_data *data, t_digit *number);

t_digit *loading_digits(char *input_number);
t_num_data *loading_data(FILE *directory, char *directory_name);

void print_number(char *input_number, char *directory_name, FILE *directory);

#endif