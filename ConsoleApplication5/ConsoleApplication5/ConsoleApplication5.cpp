// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR 20

int main()
{
	int t[ROZMIAR];
	int *wsk;
	srand(time(NULL));

	wsk = t;

	for (int i = 0; i < ROZMIAR; i++) {
		*wsk = rand();
		wsk++;
	}

	for (wsk = t ; wsk < t + ROZMIAR; wsk++) {
		printf("%d ", *wsk);
	}
	printf("\n");

	for (wsk = t; wsk < t + ROZMIAR; wsk += 2) {
		printf("%d ", *wsk);
	}
    return 0;
}

