#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_number.h"

char *loading_digits(char *input_number)
{
    int length;
    int iterator;

    length = strlen(input_number);
    char *digits = (char *)calloc((length + 1), sizeof(char));
    iterator = 0;
    while (iterator < length)
    {
        digits[iterator] = input_number[iterator];
        iterator++;
    }
    digits[iterator] = '\0';
    return (digits);
}