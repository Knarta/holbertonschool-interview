#include "sort.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

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

	for (i = left; i < right; i++)
		temp[i] = array[i];

	i = left;
	j = mid;
	k = left;

	while (i < mid && j < right)
	{
		if (temp[i] <= temp[j])
			array[k++] = temp[i++];
		else
			array[k++] = temp[j++];
	}
	while (i < mid)
		array[k++] = temp[i++];

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

	mid = left + (right - left) / 2;

	merge_sort_recursive(array, temp, left, mid);

	merge_sort_recursive(array, temp, mid, right);

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

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}
