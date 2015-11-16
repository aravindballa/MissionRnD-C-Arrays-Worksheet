/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void swapStud(struct student *a, struct student *b) {
	struct student swapper;
	swapper = *a;
	*a = *b;
	*b = swapper;
}

void sortStuds(struct student *arr, int len) {
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - i - 1; ++j) {
			if (arr[j].score < arr[j + 1].score) {
				swapStud(&arr[j], &arr[j + 1]);
			}
		}
	}
}

struct student ** topKStudents(struct student *students, int len, int K) {
	if (students == NULL || len < 1 || K < 1) return NULL;

	if (K > len) K = len;

	int i;
	struct student** topKStuds = (struct student **)malloc(K * sizeof(struct student *));

	for (i = 0; i < K; i++)
	{
		topKStuds[i] = (struct student *)malloc(sizeof(struct student));
	}

	sortStuds(students, len);

	for (i = 0; i < K; i++)
	{
		topKStuds[i] = &students[i];
	}
	return topKStuds;
}