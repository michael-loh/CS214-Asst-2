
#include "multitest.h"
#include <sys/time.h>
#include <math.h>

/*
 * Sequentially searches a section of an array for a key value.
 * This function returns the index of the value in the subarray, not the main array.
 * @param *arr Name of array
 * @param left Left index of subarray
 * @param right Right index of subarray
 * @param key Key value
 * @return Index of key value in subarray, or NOT_FOUND
 */
int sequential_search(int *arr, int left, int right, int key)
{
	int i;
	for (i = 0; i < right - left; i++) {	// return index in subarray, not index in array!
		if (arr[left + i] == key) {
			return i;
		}
	}

	return NOT_FOUND;
}

/*
 * Searches an array of integers for a key value.
 * @param *arr Name of array
 * @param size Size of array
 * @param key Integer to search for
 * @param branches Desired number of forks calls
 * @return Index of key
 */
int search(int *arr, int size, int key, int branches)
{
	int branch_size = ceil((double) size / branches);	// we will attempt to create evenly sized subarrays
	pid_t pids[branches];
	int idx = -1;

	int i;
	for (i = 0; i < branches; i++) {			// subarray bounds defined by index calculations, search them through parallel processes
		pid_t pid = fork();
		if (pid == 0) {
			int left = i * branch_size;		// beginning of subarray
			int right = fmin((i + 1) * branch_size, size);	// end of subarray, or end of array
			int result = sequential_search(arr, left, right, key);
			exit(result);
		} else {
			pids[i] = pid;				// save PIDs to reconcile results of each child process later
		}
	}
	
	for (i = 0; i < branches; i++) {			// now that all processes have been created and searched, reconcile
		int status;
		waitpid(pids[i], &status, 0);			// retrieve exit value from each child process

		unsigned char exit_code = WEXITSTATUS(status);
		if (exit_code != NOT_FOUND) {			// we don't care unless value is defined
			idx = i * branch_size + exit_code;
		}
	}

	return idx;
}

void print_mode() 
{
	printf("Welcome :)\nMulti-mode: Process\n");
}
