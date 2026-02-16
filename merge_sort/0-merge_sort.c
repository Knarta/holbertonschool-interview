#include "sort.h"

/**
 * merge - Merges two sorted subarrays into one
 * @array: Original array
 * @temp: Temporary buffer
 * @left: Starting index of left subarray
 * @mid: Ending index of left subarray (exclusive)
 * @right: Ending index of right subarray (exclusive)
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	/* Copy both halves to temp buffer */
	for (i = left; i < right; i++)
		temp[i] = array[i];

	i = left;    /* Index for left subarray */
	j = mid;     /* Index for right subarray */
	k = left;    /* Index for merged array */

	/* Merge back to original array */
	while (i < mid && j < right)
	{
		if (temp[i] <= temp[j])
			array[k++] = temp[i++];
		else
			array[k++] = temp[j++];
	}

	/* Copy remaining elements from left subarray */
	while (i < mid)
		array[k++] = temp[i++];

	/* Copy remaining elements from right subarray */
	while (j < right)
		array[k++] = temp[j++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursively sorts subarrays
 * @array: Original array
 * @temp: Temporary buffer
 * @left: Starting index
 * @right: Ending index (exclusive)
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	/* Left size <= right size: mid = left + (right - left) / 2 */
	mid = left + (right - left) / 2;

	/* Sort left array first */
	merge_sort_recursive(array, temp, left, mid);

	/* Sort right array */
	merge_sort_recursive(array, temp, mid, right);

	/* Merge the sorted halves */
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array using top-down merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	/* Single malloc call */
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);

	/* Single free call */
	free(temp);
}
