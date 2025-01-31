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


#include "stats.h"


void copy_array (unsigned char* original, unsigned char* copy, int len) {

    for (int i = 0; i < len; i++) {

        copy[i] = original[i];
        
    }

}


void print_array (unsigned char* ptr, const int len) {

    #ifdef VERBOSE

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

        PRINTF (out_str);

    #endif

}


void merge (unsigned char* ptr, int p, int q, int r) {

    // Create L ← A[p..q] and R ← A[q+1..r]
    const int n1 = q - p + 1;
    const int n2 = r - q;

    unsigned char L[n1], R[n2];

    for (int i = 0; i < n1; i++) {

        L[i] = ptr[p + i];

    }

    for (int j = 0; j < n2; j++) {

        R[j] = ptr[q + 1 + j];

    }

    // Maintain current index of sub-arrays and main array
    int i = 0;
    int j = 0;
    int k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {

            ptr[k] = L[i];
            i++;

        } else {

            ptr[k] = R[j];
            j++;

        }

        k++;

    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {

        ptr[k] = L[i];
        i++;
        k++;

    }

    while (j < n2) {

        ptr[k] = R[j];
        j++;
        k++;

    }

}


void merge_sort (unsigned char* ptr, int p, int r) {

    if (p < r) {

        int q = (p + r) / 2;

        merge_sort (ptr, p, q);
        merge_sort (ptr, q + 1, r);
        merge (ptr, p, q, r);

    }

}


void reverse_array (unsigned char* ptr, const int len) {

    int i, j;
    unsigned char tmp;

    for (i = 0, j = len -1; i < (len / 2); i++, j--) {

        tmp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = tmp;
        
    }

}


void sort_array (unsigned char* ptr, const int len) {

    int p = 0;
    int r = len - 1;

    merge_sort (ptr, p, r);

    reverse_array (ptr, len);

}


unsigned char find_maximum (unsigned char* ptr, const int len) {

    unsigned char tmp_data[len];

    copy_array (ptr, tmp_data, len);

    sort_array (tmp_data, len);

    return (tmp_data[0]);

}


unsigned char find_minimum (unsigned char* ptr, const int len) {

    unsigned char tmp_data[len];

    copy_array (ptr, tmp_data, len);

    sort_array (tmp_data, len);

    return (tmp_data[len - 1]);

}


int find_median (unsigned char* ptr, const int len) {

    unsigned char tmp_data[len];

    int median = 0;

    copy_array (ptr, tmp_data, len);

    sort_array (tmp_data, len);

    if ((len % 2) == 0) {

        median = (tmp_data[(len / 2) - 1] + tmp_data[(len / 2)]) / 2;

    } else {
        
        median = tmp_data[(len + 1) / 2 - 1];

    }

    return median;

}


int find_mean (unsigned char* ptr, const int len) {

    int i;
    int average = 0;

    if ((ptr == NULL) | (len <= 0)) { return 0; }

    for (i = 0; i < len; i++) {

        average += *ptr;
        ptr++;

    }

    return (average / len);

}


void print_statistics (unsigned char* ptr, const int len) {

    #ifdef VERBOSE
    
        char out_str[100] = "[stats.print_statistics]: median {";
        char tmp_str[10];

        int median  = find_median (ptr, len);
        int mean    = find_mean (ptr, len);
        unsigned char max = find_maximum (ptr, len);
        unsigned char min = find_minimum (ptr, len);

        sprintf (tmp_str, "%d", median);
        strcat (out_str, tmp_str);

        strcat (out_str, "}, mean {");
        sprintf (tmp_str, "%d", mean);
        strcat (out_str, tmp_str);

        strcat (out_str, "}, max {");
        sprintf (tmp_str, "%d", max);
        strcat (out_str, tmp_str);

        strcat (out_str, "}, min {");
        sprintf (tmp_str, "%d", min);
        strcat (out_str, tmp_str);

        strcat (out_str, "}.");

        PRINTF (out_str);

    #endif
    
}