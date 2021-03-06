// ConsoleApplication15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define ROZMIAR 5

int column_statistics(const int *ptr, int width, int height, int column_id, int* max, int* min, float *avg);
int row_statistics(const int *ptr, int width, int height, int row_id, int* max, int* min, float *avg);

int main()
{
	int wyniki[ROZMIAR][ROZMIAR], max = -2147483647, min = 2147483646;
	int *wskwyniki=*wyniki;
	float avg = 0.0;

	printf("Podaj liczby:\n");

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			scanf("%d", ((wskwyniki + j) + i * ROZMIAR));
		}
	}

	for (int j = 0; j < ROZMIAR; j++) {
		column_statistics(wskwyniki, ROZMIAR, ROZMIAR, j, &max, &min, &avg);
		printf("%d %d %.2f\n", min, max, avg);
	}

	for (int j = 0; j < ROZMIAR; j++) {
		max = -2147483647, min = 2147483646;
		row_statistics(wskwyniki, ROZMIAR, ROZMIAR, j, &max, &min, &avg);
		printf("%d %d %.2f\n", min, max, avg);
	}

    return 0;
}

int column_statistics(const int *ptr, int width, int height, int column_id, int* max, int* min, float *avg) {
	if (ptr == NULL || avg == NULL || min == NULL || max == NULL || column_id >= height || column_id<0 || width<0 || height<0) {
		return 0;
	}
	int maximum = *(ptr + column_id), minimum = *(ptr + column_id);
	float suma=0.0;
	for (int j = 0; j < width; j++) {
		if (minimum > *((ptr + column_id) + j * height)) {
			minimum = *((ptr + column_id) + j * height);
		}
		if (maximum < *((ptr + column_id) + j * height)) {
			maximum = *((ptr + column_id) + j * height);
		}
		suma += *((ptr + column_id) + j * height);
	}
	*min = minimum;
	*max = maximum;
	*avg = suma / height;
	getchar();
	return 1;
}
int row_statistics(const int *ptr, int width, int height, int row_id, int* max, int* min, float *avg) {
	if (ptr == NULL || avg == NULL || min == NULL || max == NULL || row_id >= height || row_id<0 || width<0 || height<0) {
		return 0;
	}

	float suma = 0.0;
	int maximum = *((ptr)+row_id * width);
	int minimum = *((ptr)+row_id * width);
	for (int i = 0; i < height; i++) {
		if (minimum > *((ptr + i) + row_id * width)) {
			minimum = *((ptr + i) + row_id * width);
		}
		if (maximum < *((ptr + i) + row_id * width)) {
			maximum = *((ptr + i) + row_id * width);
		}
		suma += *((ptr + i) + row_id * width);
	}
	*min = minimum;
	*max = maximum;
	*avg = suma / height;
	return 1;
}