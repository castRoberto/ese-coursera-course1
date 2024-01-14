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
 * @file data.c
 * @brief Basic data manipulation
 *
 * This implementation file provides an abstraction for manipulating 
 * data using function calls.
 *
 * @author Roberto Castro
 * @date January 09 2024
 *
 */

#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base) {

    // Pointer to move through the chain
    uint8_t* str = ptr;
    uint8_t isNegative = 0;
    uint8_t length = 0;

    // Handling special cases
    if (data == 0) {
        *str++ = '0';
        *str = '\0';
        return 2;  // Chain length
    }

    // Handling negative numbers in bases other than 10
    if (data < 0) {
        isNegative = 1;
        data = -data;
    }

    *str++ = '\0';
    length++;
    // Conversion process
    while (data != 0) {
        uint8_t rem = data % base;
        *str++ = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        data = data / base;
        length++;
    }

    // Add the negative sign if necessary
    if (isNegative) {
        *str++ = '-';
        length++;
    }

    //*str = '\0';

    // Invert the resulting string
    uint8_t* start = str - length;
    uint8_t* end = str - 1;

    while (start < end) {
        uint8_t temp = *start;
        *start++ = *end;
        *end-- = temp;
    }

    return length;
}

int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base) {
    // Check valid arguments
    if (ptr == NULL || digits == 0 || base < 2 || base > 16) {
        return 0;
    }

    // Initialize variables
    int32_t result = 0;
    int32_t sign = 1;

    // Handle sign
    if (*ptr == '-') {
        sign = -1;
        ++ptr;
        --digits;
    }

    // Convert characters to integer
    while (digits > 1) {
        uint8_t digit_value;

        if (*ptr >= '0' && *ptr <= '9') {
            digit_value = *ptr - '0';
        } else if (*ptr >= 'a' && *ptr <= 'f') {
            digit_value = 10 + (*ptr - 'a');
        } else if (*ptr >= 'A' && *ptr <= 'F') {
            digit_value = 10 + (*ptr - 'A');
        } else {
            // Invalid character
            return 0;
        }

        // Check if the digit is valid for the base
        if (digit_value >= base) {
            return 0;
        }

        // Update the result
        result += digit_value * pow (base, digits - 2);

        // Move to next character
        ++ptr;
        --digits;
    }

    // Apply the sign
    result *= sign;

    return result;
}
