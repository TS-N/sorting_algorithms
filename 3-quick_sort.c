#include "sort.h"

void	sort(int *array, size_t size, size_t lo, size_t hi);

/**
 * quick_sort - quick sort algo on an array in C using Lomuto partion scheme
 * @array: the array to sort
 * @size: the size of the array
 **/
void quick_sort(int *array, size_t size)
{
	if (size > 1)
		sort(array, size,  0, size - 1);
}

/**
  * sort - the recursive quicksort algo
  * @array: the array to sort
  * @size: the size of the array (for print func)
  * @lo: the lowest index of the sub-array
  * @hi: the highest index of the sub-array
  **/
void	sort(int *array, size_t size, size_t lo, size_t hi)
{
	size_t	i, j;
	int	buf;
	int	pivot;

	if (lo > hi || hi - lo < 1)
		return;
	pivot = array[hi];
	j = lo;
	i = lo;
	while (j < hi)
	{
		if (array[j] < pivot)
		{
			if (j != i)
			{
				buf = array[j];
				array[j] = array[i];
				array[i] = buf;
				print_array(array, size);
			}
			++i;
		}
		++j;
	}
	if (hi != i && array[hi] != array[i])
	{
		array[hi] = array[i];
		array[i] = pivot;
		print_array(array, size);
	}
	if (i > 0)
		sort(array, size, lo, i - 1);
	sort(array, size, i + 1, hi);
}
