// ConsoleApplication6.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR 20

int main()
{
	float t[ROZMIAR];
	float *wsk=t;
	srand((unsigned int)time(NULL));

	for (wsk = t; wsk < t + ROZMIAR; wsk++) {
		*wsk = ((float)rand() / (float)(RAND_MAX));
	}

	for (wsk = t; wsk < t + ROZMIAR; wsk++) {
		printf("%f ", *wsk);
	}
	printf("\n");

	for (wsk = t; wsk < t + ROZMIAR; wsk += 2) {
		printf("%f ", *wsk);
	}
	getchar();
	return 0;
}
