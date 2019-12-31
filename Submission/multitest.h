/*
 * multitest.h
 *
 *  Created on: Nov 8, 2019
 *      Author: micha
 */

#ifndef MULTITEST_H_
#define MULTITEST_H_


#include <stdlib.h>
#include <stdio.h>

#define NOT_FOUND 255

/*
 * Searches an array of integers for a key value.
 * The key will always be in the array.
 * @param *arr Pointer to array
 * @param size Size of array
 * @param key Integer to search for
 * @param branches Desired number of forks/threads to create
 * @return Pointer to element
 */
int search(int *arr, int size, int key, int branches);
int subarr_search(int *arr, int size, int subarr_size, int key);

#endif /* MULTITEST_H_ */
