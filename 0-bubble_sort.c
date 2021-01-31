#include "sort.h"

/**
  * bubble_sort - bubble sort algo in C
  * @array: the array to sort
  * @size: the size of the array
  * Return: nothing
  **/
void bubble_sort(int *array, size_t size)
{
	size_t	i;
	size_t	di;
	int	buf;
	char	swp;

	i = 0;
	di = 1;
	while (di < size)
	{
		i = 0;
		swp = '0';
		while (i < size - di)
		{
			if (array[i] > array[i + 1])
			{
				swp = '1';
				buf = array[i];
				array[i] = array[i + 1];
				array[i + 1] = buf;
				print_array(array, size);
			}
			++i;
		}
		if (swp == '0')
			break;
		++di;
	}
}
