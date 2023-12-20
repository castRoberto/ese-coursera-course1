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
 * @file stats.h
 * @brief Headers for statistics
 *
 * In this file the prototypes of all the functions that calculate 
 * attributes of matrices are declared.
 *
 * @author Roberto Castro Beltran
 * @date 20 december 2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include <stdio.h>
#include <string.h>

/**
 * @brief Print the array to the screen
 *
 * Given an array of data and a length, print the array to the screen.
 *
 * @param ptr Data array
 * @param len Data array length 
 */
void print_array (unsigned char* ptr, const int len);


#endif /* __STATS_H__ */
