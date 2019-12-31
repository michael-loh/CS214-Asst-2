
#include "multitest.h"
#include <pthread.h>
#include <unistd.h>
#include <math.h>
/*
 * Arguments to search().
 * This struct will help us call search() with a thread.
 */
typedef struct thread_args {
	int *arr;	// name of array
	int left;	// left index of subarray
	int right;	// right index of subarray
	int key;	// key value
	int *index;	// return value of search(), contains index of key
} thread_args;

/*
 * Searches a section of an integer array for a key value.
 * @param *arr Name of array
 * @param left Left index of subarray
 * @param right Right index of subarray
 * @param key Key value
 * @return Index of key value, or -1 if not found
 */
int sequential_search(int *arr, int left, int right, int key)
{
	int i;
	for (i = left; i < right; i++) {
		if (arr[i] == key) {
			return i;
		}
	}

	return -1;
}

/*
 * Enables search() to be called by a thread.
 * @param *vargp Struct containing arguments of search()
 */
void *search_thread(void *vargp) {

	thread_args *func_args = (thread_args*) vargp;	// cast vargp to struct

	int found = sequential_search(func_args->arr, func_args->left, func_args->right, func_args->key);

	if(found != -1) {	// only record return value if it is the actual index, or you will overwrite the correct index!
		*(func_args->index) = found;
	}

	free(func_args);
}

int search(int *arr, int size, int key, int branches)
{
	int subarr_size = ceil((double) size / branches);	//subarr_size = size / num of subsections

	int *index = malloc(sizeof(int));	// pointer to heap memory, can be modified by any thread
	*index = -1;

	pthread_t tid[branches];

	int i;
	for(i = 0; i < branches; i++) {
		thread_args *func_args = malloc(sizeof(thread_args));
		func_args->arr = arr;
		func_args->index = index;
		func_args->left = i * subarr_size;
		func_args->right = (i+1)* subarr_size;
		if(func_args->right > size){	// creates smaller subarray for final branch, if necessary
			func_args->right = size;
		}
		func_args->key = key;

		pthread_create(&tid[i], NULL, search_thread, (void*)func_args);
	}

	for(i = 0; i < branches; i++) {
		(void) pthread_join(tid[i], NULL);
	}

	return *index;
}

void print_mode() 
{
	printf("Welcome :)\nMulti-mode: Thread\n");
}
