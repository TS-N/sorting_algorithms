#include "sort.h"

/**
 * selection_sort - selection sort algo on an array
 * @array: the array to sort
 * @size: the size of the array
 **/
void selection_sort(int *array, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	min_elem;
	int	n;

	i = 0;
	while (i < size)
	{
		j = i;
		min_elem = j;
		while (j < size)
		{
			if (array[j] < array[min_elem])
				min_elem = j;
			++j;
		}
		if (i != min_elem)
		{
			n = array[i];
			array[i] = array[min_elem];
			array[min_elem] = n;
			print_array(array, size);
		}
		++i;
	}
}
