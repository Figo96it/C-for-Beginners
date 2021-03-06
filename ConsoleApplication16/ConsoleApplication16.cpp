// ConsoleApplication16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define ROZMIAR 5

int dd_test(const int *ptr, int width, int height);

int main()
{
	int wyniki[ROZMIAR][ROZMIAR];
	int *wskwyniki = *wyniki;

	printf("Podaj liczby:\n");

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			scanf("%d", ((wskwyniki + j) + i * ROZMIAR));
		}
	}

	if ((dd_test(wskwyniki, ROZMIAR, ROZMIAR))==1) {
		printf("TAK");
	}
	else {
		printf("NIE");
	}

    return 0;
}

int dd_test(const int *ptr, int width, int height) {
	if (ptr == NULL || width <= 0 || height <= 0 || width!=height) {
		return -1;
	}
	
	int suma;
	for (int i = 0; i < height; i++) {
		suma = 0;
		for (int j = 0; j < width; j++) {
			suma += abs(*((ptr + j) + i * width));
		}
		if (abs(*((ptr + i)+i*width)) <= (suma-abs(*((ptr+i)+i*width)))) {
			return 0;
		}
	}
	return 1;
}
