// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define ROZMIAR 10

int is_It_APrime_Number(int *wsk);

int main()
{
	int wyniki[ROZMIAR][ROZMIAR];
	int *wswyniki;

	wswyniki = wyniki[0];
	printf("Podaj liczby:\n");

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			scanf("%d", ((wswyniki + j) + i * ROZMIAR));
				while (is_It_APrime_Number(((wswyniki + j) + i * ROZMIAR))) {
					scanf("%d", ((wswyniki + j) + i * ROZMIAR));
				}
		}
	}

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			if (i%3==0 && j%3==0) {
				printf("%d ", *((wswyniki + j) + i * ROZMIAR));
			}
		}
	}

	return 0;
}

int is_It_APrime_Number(int *wsk) {
	if (*wsk<2 || wsk==NULL) {
		return 0;
	}
	
	int licznik = 0;
	for (int i = 1; i < *wsk; i++) {
		if (*wsk % i == 0) {
			licznik++;
		}
	}
	if (licznik > 2) {
		return 0;
	}
	return 1;
}
