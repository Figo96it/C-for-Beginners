// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR 100

int main()
{
	double t[ROZMIAR];
	double *wsk = t;
	double suma=0.0, srednia=0.0;
	srand((unsigned int)time(NULL));

	for (wsk = t; wsk < t + ROZMIAR; wsk++) {
		*wsk = ((double)rand() / (double)(RAND_MAX));
	}

	for (wsk = t; wsk < t + ROZMIAR; wsk++) {
		printf("%f ", *wsk);
	}
	printf("\n");

	for (wsk = t; wsk < t + ROZMIAR; wsk ++) {
		suma += *wsk;
	}
	srednia = suma / ROZMIAR;

	printf("%.2f\n", suma);
	printf("%.2f", srednia);
	return 0;
}
