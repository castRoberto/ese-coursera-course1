/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/

/**
 * @file stats.c
 * @brief Implementation of statistical operations
 *
 * Implementation of statistical functions on a matrix.
 *
 * @author Roberto Castro Beltran
 * @date 20 december 2023
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_array (test, SIZE);

  return 0;

}

void print_array (unsigned char* ptr, const int len) {

    char out_str[200] = "\n[print_array]: [\n";
    char tmp_str[10];
    int columns = 8;

    for (int i = 0; i < len; i++) {
        strcat (out_str, "\t");
        sprintf (tmp_str, "%d", ptr[i]);
        strcat (out_str, tmp_str);

        if (((i + 1) % columns) == 0) {
            strcat (out_str, "\n");
        }
    }

    strcat (out_str, "]\n\n");

    printf (out_str);

}
