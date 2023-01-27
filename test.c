// C Program to illustrate Generic Quicksort Function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debug.h"
#include <unistd.h>
#include <signal.h>
/* Swaps position of strings in array (char**) */
void swap(char **a, char **b) {
	char *temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(char * arr[], unsigned int length) {
	unsigned int i, piv = 0;
	if (length <= 1) 
		return;
	
	printf("1> %d : piv = %d -> ", length, piv);
	for (int j = 0; arr[j]; j++)
		printf("%s | ", arr[j]);
	printf("\n");
	for (i = 0; i < length; i++) {
		printf("%s - %s |", arr[i], arr[length -1]);
		// if curr str < pivot str, move curr into lower array and  lower++(pvt)
		if (strcmp(arr[i], arr[length -1]) < 0) 	//use string in last index as pivot
			swap(arr + i, arr + piv++);
	}
	nl
	//move pivot to "middle"
	printf("2> %d : piv = %d -> ", length, piv);
	for (int j = 0; arr[j]; j++)
		printf("%s | ", arr[j]);
	printf("\n");
	swap(arr + piv, arr + length - 1);
	printf("3> %d : piv = %d -> ", length, piv);
	for (int j = 0; arr[j]; j++)
		printf("%s | ", arr[j]);
	printf("\n");
	//recursively sort upper and lower
	quicksort(arr, piv++);			//set length to current pvt and increase for next call
	quicksort(arr + piv, length - piv);
}
#include <string.h>
int main(int ac, char **av, char **env)
{
	for (int i = 0; i <  3 ; i++)
	{
		if (!fork())
		{
			for (int j = 0; j < 30; j++)
			{
			printd(i)
			sleep(2);
			}
			exit(0);
		}
	}
	sleep (5);
	prints("I'm parent")
	sleep(1);
	prints("Killing...")
	printd(kill(0, SIGTERM))
	prints("Done.")
	sleep (5);

	// while (*env)
	// 		prints(*env++)
	// int (*fd)[3];
	// printz(sizeof(int [3]))
	// printz(sizeof(*fd))
	// Your C Code
	// char* a[] = {"bbc", "xcd", "ede", "def",
	// 		"afg", "hello", "hmmm", "okay", "how" , NULL};

	// int b[] = { 45, 78, 89, 65, 70, 23, 44 };
	// int* p = b;
	// quicksort(a,9);

	// for (int i = 0; i < 9; i++)
	// 	printf("%s ", a[i]);
	// printf("\n");
	return 0;
}
