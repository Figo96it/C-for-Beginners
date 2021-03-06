// ConsoleApplication14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define ROZMIAR 100

int read_vector(int* vector, int max_size);
int find(int to_find, const int* vector, int size);

int main()
{
	int wyniki[ROZMIAR], rozmiar = 0, element = 0;
	rozmiar=read_vector(wyniki,ROZMIAR);
	printf("podaj element ktory chcesz znalezc: ");
	scanf("%d", &element);
	printf("indeks szukanego elementu: %d", find(element, wyniki, rozmiar));
    return 0;
}

int read_vector(int* vector, int max_size) {
	if (vector == NULL || max_size <= 0) {
		return -1;
	}
	int x = 0;
	printf("ile ma byc elementow wpisz:\n");
	scanf("%d", &x);
	while (!(x < max_size)) {
		scanf("%d", &x);
	}
	printf("wprowadz elementy:\n");
	for (int i = 0; i < x; i++) {
		scanf("%d", (vector + i));
	}
	return x;
}

int find(int to_find, const int* vector, int size) {
	if (vector == NULL || size <= 0) {
		return -1;
	}
	int indeks = -1;
	for (int i = 0; i < size; i++) {
		if (*(vector + i) == to_find) {
			indeks = i;
		}
	}
	return indeks;
}

