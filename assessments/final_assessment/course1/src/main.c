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
 * @file main.c
 * @brief Main entry point to the C1FINAL Assessment
 *
 * This file contains the main code for the C1FINAL evaluation. Contains 
 * preprocessor logic to invoke the course1 test routine
 *
 * @author Roberto Castro
 * @date January 06 2024
 *
 */

#include "course1.h"

int main () {

    #ifdef COURSE1
        course1();
    #endif

    return 0;
}