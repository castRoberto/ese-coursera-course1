/******************************************************************************
 * Copyright (C) 2024 by Roberto Castro
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Roberto Castro are not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Basic data manipulation
 *
 * This header file provides an abstraction for manipulating data 
 * using function calls
 *
 * @author Roberto Castro
 * @date January 09 2024
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stddef.h>
#include <math.h>

#define BASE_10 (10)
#define BASE_16 (16)

/**
 * @brief Convert from integer to string
 *
 * Given an integer, a string pointer, and the base number, 
 * convert the integer to a character string.
 *
 * @param data Integer to convert
 * @param ptr String with converted value
 * @param base Integer base
 *
 * @return length.
 */
uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base);

/**
 * @brief Convert from string to integer
 *
 * Given a string pointer, digits, and the base number, 
 * convert the string to a integer.
 *
 * @param ptr String to convert
 * @param digits Number of digits of the number
 * @param base Integer base
 *
 * @return converted number.
 */
int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */