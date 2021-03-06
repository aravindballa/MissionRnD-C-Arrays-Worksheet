/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL || len <= 0) return NULL;
	int i, tmp, j;
	
	for (i = 0; i < len; i++)
	{
		if (Arr[i] > num) break;
	}

	len++;
	Arr = (int *)realloc(Arr, sizeof(int)*len);

	if (i == len - 1)
	{
		Arr[i] = num;
		return Arr;
	}
	
	tmp = Arr[i];
	Arr[i] = num;

	
	
	for (j = len - 1; j > i+1; j--)
	{
		Arr[j] = Arr[j - 1];
	}

	Arr[j] = tmp;

	return Arr;
}