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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Move values from one memory location to another
 *
 * Given two pointers to byte data sets, move a number of bytes 
 * from one location to the other
 * 
 * Instructions:
 *  1. This function takes two byte pointers (one source and one destination)
 *     and a length of bytes to move from the source location to the destination.
 *  2. The behavior should handle overlap of source and destination. Copy should 
 *     occur, with no data corruption.
 *  3. All operations need to be performed using pointer arithmetic, not array 
 *     indexing
 *  4. Should return a pointer to the destination (dst).
 *
 * @param src Pointer to data array
 * @param dst Number of elements to set to zero
 * @param length Number of bytes to move
 *
 * @return Pointer to dst.
 */
uint8_t* my_memmove(uint8_t* src, uint8_t* dst, size_t length);

/**
 * @brief Reserve words in dynamic memory
 *
 * Given a number of words, reserve the appropriate space in dynamic 
 * memory
 * 
 * Instructions:
 * 
 *  1. This should take number of words to allocate in dynamic memory
 * 
 *  2. All operations need to be performed using pointer arithmetic, 
 *     not array indexing
 * 
 *  3. Should return a pointer to memory if successful, or a Null 
 *     Pointer if not successful
 *
 * @param length Number of words to reserve
 * 
 * @return Pointer to memory
 */
int32_t* reserve_words(size_t length);

/**
 * @brief Free dynamic memory
 *
 * Given a pointer to dynamic memory, the occupied space is freed 
 *
 * @param src Pointer to data array
 *
 * @return void.
 */
void free_words(int32_t* src);

/**
 * @brief Move values from one memory location to another
 *
 * Given two pointers to byte data sets, move a number of bytes from one 
 * location to the other without handling overlap
 * 
 * Instructions:
 *  1. This function takes two byte pointers (one source and one destination) 
 *     and a length of bytes to copy from the source location to the destination.
 *  2. The behavior is undefined if there is overlap of source and destination. 
 *     Copy should still occur, but will likely corrupt your data.
 *  3. All operations need to be performed using pointer arithmetic, not array 
 *     indexing
 *  4. Should return a pointer to the destination (dst).
 *
 * @param src Pointer to data array
 * @param dst Number of elements to set to zero
 * @param length Number of bytes to move
 *
 * @return Pointer to dst.
 */
uint8_t* my_memcopy(uint8_t* src, uint8_t* dst, size_t length);

/**
 * @brief Assign a value to an entire array
 *
 * Given a vector and a value, assign the given value to each 
 * position
 * 
 * Instructions:
 *  1. This should take a pointer to a source memory location, a length 
 *     in bytes and set all locations of that memory to a given value.
 *  2. All operations need to be performed using pointer arithmetic, 
 *     not array indexing.
 *  3. Should return a pointer to the source (src).
 *  4. You should NOT reuse the set_all() function
 *
 * @param src Pointer to data array
 * @param length Number of bytes to move
 * @param value Value to set
 *
 * @return Pointer to src.
 */
uint8_t* my_memset(uint8_t* src, size_t length, uint8_t value);

/**
 * @brief Assign cero to an entire array
 *
 * Given a vector, assign cero to each position
 * 
 * Instructions:
 *  1. This should take a pointer to a memory location, a length in 
 *     bytes and zero out all of the memory.
 *  2. All operations need to be performed using pointer arithmetic, 
 *     not array indexing
 *  3. Should return a pointer to the source (src).
 *  4. You should NOT reuse the clear_all() function
 *
 * @param src Pointer to data array
 * @param length Number of bytes to move
 * @param value Value to set
 *
 * @return Pointer to src.
 */
uint8_t* my_memzero(uint8_t* src, size_t length);

#endif /* __MEMORY_H__ */
