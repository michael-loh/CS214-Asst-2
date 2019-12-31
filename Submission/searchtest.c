
#include "multitest.h"
#include <math.h>

/*
 * Generates a randomized integer array.
 * @param *arr Pointer to array
 * @param size Size of array
 */
void generate(int *arr, int size)
{
	int i;
	for(i = 0; i < size; i++) {		// fill array with distinct values
		arr[i] = i;
	}

	for(i = 0; i < size; i++) {		// scramble the array
		int t1 = rand() % size;		// generate two random indices
		int t2 = rand() % size;

		int temp = arr[t1];		// swap elements at random indices
		arr[t1] = arr[t2];
		arr[t2] = temp;
	}
}

/*
 * "Randomizes" an already randomized array by swapping the key with a random index.
 * @param *arr Pointer to array
 * @param size Size of array
 * @param *ptr Pointer to reviously found key
 */
void randomize(int *arr, int size, int *ptr)
{
	int idx = rand() % size;		// generate random index

	int temp = *ptr;			// swap with key
	*ptr = arr[idx];
	arr[idx] = temp;
}

/*
 * Performs a regular sequential search on an array.
 * @param *arr Array of integers 
 * @param size Size of array
 * @param key Target value
 * @return Index of key
 */
int control_search(int *arr, int size, int key) {
	int i;
	for (i = 0; i < size; i++) {
		if (key == arr[i]) {
			return i;
		}
	}
	return -1;
}

/*
 * Control case.
 * Performs regular sequential search on the same parameters as workload_a().
 */

void control_a() 
{
	printf("control_a()\n");
	int size;
	int *arr;
	struct timeval start, end;
	double time_elapsed;

	double total_time;
	double total_time_squared;
	double mu;
	double std_dev;
	int idx;

	for(size = 250; size <= 20000; size += 50) {
		arr = malloc(sizeof(int) * size);
		generate(arr, size);

		total_time = 0;
		total_time_squared = 0;
		std_dev = 0;

		int i;
		for(i = 0; i < 50; i++) {
			int key = rand() % size;
			idx = -1;

			gettimeofday(&start, NULL);
			idx = control_search(arr, size, key);
			gettimeofday(&end, NULL);

			randomize(arr, size, &arr[idx]);

			time_elapsed = (end.tv_sec - start.tv_sec) * 1e6;
			time_elapsed = (time_elapsed + (end.tv_usec - start.tv_usec)) * 1e-6;
			total_time += time_elapsed;
			total_time_squared += time_elapsed * time_elapsed;
			mu = total_time / i;
			std_dev = sqrt((total_time_squared / i) - (mu * mu));
		}
		double avg_time = total_time / 50;

		free(arr);
		//printf("%d %f %f\n", size, avg_time, std_dev);
		printf("Found key at index %d| Size: %d | No branches | Mean Time: %fs | Standard Deviation: %f\n", idx, size, avg_time, std_dev);
	}
}

/*
 * Control case.
 * Performs regular sequential search on the same parameters as workload_b().
 */
void control_b()
{
	printf("control_b()\n");
	int size = 1000;
	int branches = 8;
	int *arr = malloc(sizeof(int) * size);
	generate(arr,size);

	struct timeval start, end;
	double time_elapsed;

	double total_time;
	double total_time_squared;
	double mu;
	double std_dev;
	int idx;

	for(branches = 8; branches <= 60; branches += 1) {

		total_time = 0;

		int i;
		for(i = 0; i < 50; i++) {
			int key = rand() % size;
			idx = -1;

			gettimeofday(&start, NULL);
			idx = control_search(arr, size, key);
			gettimeofday(&end, NULL);

			randomize(arr, size, &arr[idx]);

			time_elapsed = (end.tv_sec - start.tv_sec) * 1e6;
			time_elapsed = (time_elapsed + (end.tv_usec - start.tv_usec)) * 1e-6;
			total_time += time_elapsed;
			total_time_squared += time_elapsed * time_elapsed;
			mu = total_time / i;
			std_dev = sqrt((total_time_squared / i) - (mu * mu));
		}


		double avg_time = total_time / 50;

		//printf("%d %f %f\n", size, avg_time, std_dev);
		printf("Found key at index %d| Size: %d | No branches | Mean Time: %fs | Standard Deviation: %f\n", idx, size, avg_time, std_dev);
	}
	free(arr);

}

/*
 * Control case.
 * Performs regular sequential search on the same parameters as workload_c().
 */
void control_c()
{
	printf("control_c()\n");
	int size = 5000;
	int branches = 20;
	int *arr = malloc(sizeof(int) * size);
	generate(arr,size);

	struct timeval start, end;
	double time_elapsed;

	double total_time;
	double total_time_squared;
	double mu;
	double std_dev;
	int idx;

	for(branches = 20; branches <= 70; branches += 1) {

		total_time = 0;

		int i;
		for(i = 0; i < 50; i++) {
			int key = rand() % size;
			idx = -1;

			gettimeofday(&start, NULL);
			idx = control_search(arr, size, key);
			gettimeofday(&end, NULL);

			randomize(arr, size, &arr[idx]);

			time_elapsed = (end.tv_sec - start.tv_sec) * 1e6;
			time_elapsed = (time_elapsed + (end.tv_usec - start.tv_usec)) * 1e-6;
			total_time += time_elapsed;
			total_time_squared += time_elapsed * time_elapsed;
			mu = total_time / i;
			std_dev = sqrt((total_time_squared / i) - (mu * mu));
		}

		double avg_time = total_time / 50;

		//printf("%d %f %f\n", size, avg_time, std_dev);
		printf("Found key at index %d| Size: %d | No branches | Mean Time: %fs | Standard Deviation: %f\n", idx, size, avg_time, std_dev);
	}

	free(arr);
}

/*
 * Control case.
 * Performs regular sequential search on the same parameters as workload_d().
 */
void control_d()
{
	printf("control_d()\n");
	int size = 10000;
	int branches = 40;

	int *arr = malloc(sizeof(int) * size);
	generate(arr,size);

	struct timeval start, end;
	double time_elapsed;

	double total_time;
	double total_time_squared;
	double mu;
	double std_dev;
	int idx;

	for(branches = 40; branches <= 90; branches += 1) {

		total_time = 0;

		int i;
		for(i = 0; i < 50; i++) {
			int key = rand() % size;
			idx = -1;

			gettimeofday(&start, NULL);
			idx = control_search(arr, size, key);
			gettimeofday(&end, NULL);

			randomize(arr, size, &arr[idx]);

			time_elapsed = (end.tv_sec - start.tv_sec) * 1e6;
			time_elapsed = (time_elapsed + (end.tv_usec - start.tv_usec)) * 1e-6;
			total_time += time_elapsed;
			total_time_squared += time_elapsed * time_elapsed;
			mu = total_time / i;
			std_dev = sqrt((total_time_squared / i) - (mu * mu));
		}

		double avg_time = total_time / 50;

		//printf("%d %f %f\n", size, avg_time, std_dev);
		printf("Found key at index %d| Size: %d | No branches | Mean Time: %fs | Standard Deviation: %f\n", idx, size, avg_time, std_dev);
	}
	free(arr);
}

/*
 * Control case.
 * Performs regular sequential search on the same parameters as workload_e().
 */
void control_e()
{
	printf("control_e()\n");
	int size = 20000;
	int branches = 80;

	int *arr = malloc(sizeof(int) * size);
	generate(arr,size);

	struct timeval start, end;
	double time_elapsed;

	double total_time;
	double total_time_squared;
	double mu;
	double std_dev;
	int idx;

	for(branches = 80; branches <= 130; branches += 1) {

		total_time = 0;

		int i;
		for(i = 0; i < 50; i++) {
			int key = rand() % size;
			idx = -1;

			gettimeofday(&start, NULL);
			idx = control_search(arr, size, key);
			gettimeofday(&end, NULL);

			randomize(arr, size, &arr[idx]);

			time_elapsed = (end.tv_sec - start.tv_sec) * 1e6;
			time_elapsed = (time_elapsed + (end.tv_usec - start.tv_usec)) * 1e-6;
			total_time += time_elapsed;
			total_time_squared += time_elapsed * time_elapsed;
			mu = total_time / i;
			std_dev = sqrt((total_time_squared / i) - (mu * mu));
		}

		double avg_time = total_time / 50;

		//printf("%d %f %f\n", size, avg_time, std_dev);
		printf("Found key at index %d| Size: %d | No branches | Mean Time: %fs | Standard Deviation: %f\n", idx, size, avg_time, std_dev);
	}
	free(arr);
}

/*
 * Testing the effectiveness of parallelism over a range of array sizes.
 * Subarray size remains consistent at 250.
 * Array sizes range from 250-50000, in increments of 10.
 * Times represent the average of 50 trials over a given array size.
 */
void workload_a()
{
	printf("workload_a()\n");

	int size;

	struct timeval start, end;
	double time_elapsed;

	double total_time;
	double total_time_squared;
	double mu;
	double std_dev;
	int idx;

	for(size = 250; size <= 20000; size += 50) {


		int *arr = malloc(sizeof(int) * size);
		generate(arr, size);

		int branches = ceil((double) size / 250);
		total_time = 0;

		int i;
		for(i = 0; i < 50; i++) {
			int key = rand() % size;
			idx = -1;

			gettimeofday(&start, NULL);
			idx = search(arr, size, key, branches);
			gettimeofday(&end, NULL);

			randomize(arr, size, &arr[idx]);

			time_elapsed = (end.tv_sec - start.tv_sec) * 1e6;
			time_elapsed = (time_elapsed + (end.tv_usec - start.tv_usec)) * 1e-6;
			total_time += time_elapsed;
			total_time_squared += time_elapsed * time_elapsed;
			mu = total_time / i;
			std_dev = sqrt((total_time_squared / i) - (mu * mu));
		}
		double avg_time = total_time / 50;

		free(arr);
		//printf("%d %d %f %f\n", size, branches, avg_time, std_dev);
		printf("Found key at index %d| Size: %d | Branches: %d | Mean Time: %fs | Standard Deviation: %f\n", idx, size, branches, avg_time, std_dev);
	}
}

/*
 *  Testing effective of parallelism over array size 1000
 *  amount of branches from 8-60. Increase by 1 every iteration
 *  will test each branch value 50 times
 */
void workload_b()
{
	printf("workload_b()\n");
	int size = 1000;
	int branches = 8;
	int *arr = malloc(sizeof(int) * size);
	generate(arr,size);

	struct timeval start, end;
	double time_elapsed;

	double total_time;
	double total_time_squared;
	double mu;
	double std_dev;
	int idx;

	for(branches = 8; branches <= 60; branches += 1) {

		int i;
		total_time = 0;

		for(i = 0; i < 50; i++) {
			int key = rand() % size;
			idx = -1;

			gettimeofday(&start, NULL);
			idx = search(arr, size, key, branches);
			gettimeofday(&end, NULL);

			randomize(arr, size, &arr[idx]);

			time_elapsed = (end.tv_sec - start.tv_sec) * 1e6;
			time_elapsed = (time_elapsed + (end.tv_usec - start.tv_usec)) * 1e-6;
			total_time += time_elapsed;
			total_time_squared += time_elapsed * time_elapsed;
			mu = total_time / i;
			std_dev = sqrt((total_time_squared / i) - (mu * mu));
		}

		double avg_time = total_time / 50;

		//printf("%d %d %f %f\n", size, branches, avg_time, std_dev);
		printf("Found key at index %d| Size: %d | Branches: %d | Mean Time: %fs | Standard Deviation: %f\n", idx, size, branches, avg_time, std_dev);
	}
	free(arr);
}

/*
 *  Testing effective of parallelism over array size 15000
 *  amount of branches from 20-70. Increase by 1 every iteration
 *  will test each branch value 50 times
 */
void workload_c()
{
	printf("workload_c()\n");
	int size = 5000;
	int branches = 20;
	int *arr = malloc(sizeof(int) * size);
	generate(arr,size);

	struct timeval start, end;
	double time_elapsed;

	double total_time;
	double total_time_squared;
	double mu;
	double std_dev;
	int idx;

	for(branches = 20; branches <= 70; branches += 1) {

		int i;
		total_time = 0;

		for(i = 0; i < 50; i++) {
			int key = rand() % size;
			idx = -1;

			gettimeofday(&start, NULL);
			idx = search(arr, size, key, branches);
			gettimeofday(&end, NULL);

			randomize(arr, size, &arr[idx]);

			time_elapsed = (end.tv_sec - start.tv_sec) * 1e6;
			time_elapsed = (time_elapsed + (end.tv_usec - start.tv_usec)) * 1e-6;
			total_time += time_elapsed;
			total_time_squared += time_elapsed * time_elapsed;
			mu = total_time / i;
			std_dev = sqrt((total_time_squared / i) - (mu * mu));
		}

		double avg_time = total_time / 50;

		//printf("%d %d %f %f\n", size, branches, avg_time, std_dev);
		printf("Found key at index %d| Size: %d | Branches: %d | Mean Time: %fs | Standard Deviation: %f\n", idx, size, branches, avg_time, std_dev);
	}

	free(arr);
}

/*
 *  Testing effective of parallelism over array size 10000
 *  amount of branches from 20-70. Increase by 1 every iteration
 *  will test each branch value 50 times
 */
void workload_d()
{
	printf("workload_d()\n");
	int size = 10000;
	int branches = 40;
	int *arr = malloc(sizeof(int) * size);
	generate(arr,size);

	struct timeval start, end;
	double time_elapsed;

	double total_time;
	double total_time_squared;
	double mu;
	double std_dev;
	int idx;

	for(branches = 40; branches <= 90; branches += 1) {


		int i;
		total_time = 0;

		for(i = 0; i < 50; i++) {
			int key = rand() % size;
			idx = -1;

			gettimeofday(&start, NULL);
			idx = search(arr, size, key, branches);
			gettimeofday(&end, NULL);

			randomize(arr, size, &arr[idx]);

			time_elapsed = (end.tv_sec - start.tv_sec) * 1e6;
			time_elapsed = (time_elapsed + (end.tv_usec - start.tv_usec)) * 1e-6;
			total_time += time_elapsed;
			total_time_squared += time_elapsed * time_elapsed;
			mu = total_time / i;
			std_dev = sqrt((total_time_squared / i) - (mu * mu));
		}

		double avg_time = total_time / 50;

		//printf("%d %d %f %f\n", size, branches, avg_time, std_dev);
		printf("Found key at index %d| Size: %d | Branches: %d | Mean Time: %fs | Standard Deviation: %f\n", idx, size, branches, avg_time, std_dev);
	}

	free(arr);
}

/*
 *  Testing effective of parallelism over array size 20000
 *  amount of branches from 80-130. Increase by 1 every iteration
 *  will test each branch value 50 times
 */
void workload_e()
{
	printf("workload_e()\n");
	int size = 20000;
	int branches = 80;
	int *arr = malloc(sizeof(int) * size);
	generate(arr,size);

	struct timeval start, end;
	double time_elapsed;

	double total_time;
	double total_time_squared;
	double mu;
	double std_dev;
	int idx;

	for(branches = 80; branches <= 130; branches += 1) {

		int i;
		total_time = 0;

		for(i = 0; i < 50; i++) {
			int key = rand() % size;
			idx = -1;

			gettimeofday(&start, NULL);
			idx = search(arr, size, key, branches);
			gettimeofday(&end, NULL);

			randomize(arr, size, &arr[idx]);

			time_elapsed = (end.tv_sec - start.tv_sec) * 1e6;
			time_elapsed = (time_elapsed + (end.tv_usec - start.tv_usec)) * 1e-6;
			total_time += time_elapsed;
			total_time_squared += time_elapsed * time_elapsed;
			mu = total_time / i;
			std_dev = sqrt((total_time_squared / i) - (mu * mu));
		}

		double avg_time = total_time / 50;

		//printf("%d %d %f %f\n", size, branches, avg_time, std_dev);
		printf("Found key at index %d| Size: %d | Branches: %d | Mean Time: %fs | Standard Deviation: %f\n", idx, size, branches, avg_time, std_dev);
	}

	free(arr);
}

void print_arr(int *arr, int size)
{
	int i;
	for(i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	print_mode();

	control_a();
	control_b();
	control_c();
	control_d();
	control_e();


	workload_a();
	workload_b();
	workload_c();
	workload_d();
	workload_e();


	return 0;
}
