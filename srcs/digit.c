#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_number.h"

t_digit *loading_digits(char *input_number)
{
    int length;
    int iterator;

    length = strlen(input_number);
    t_digit *digits = (t_digit *)malloc((length + 1) * sizeof(t_digit));
    iterator = 0;
    while (iterator < length)
    {
        digits[iterator].nbr = input_number[iterator];
        digits[iterator].index = length - iterator - 1;
        digits[iterator].length = length;
        digits[iterator].book_mark = MID;
        iterator++;
    }
    digits[iterator].book_mark = END;
    return (digits);
}