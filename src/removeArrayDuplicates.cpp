/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len < 1) return NULL;
	int eachCount[10] = { 0 };
	int i, j = 0;
	for (i = 0; i < len; i++)
	{
		eachCount[Arr[i]]++;
	}
	for (i = 0; i < 10; i++)
	{
		if (eachCount[i] > 0) Arr[j++] = i;
	}
	
}