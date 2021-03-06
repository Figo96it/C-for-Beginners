// ConsoleApplication13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define ROZMIAR 100

int reverse_vector(int* tab, int size);
int display_vector(const int* tab, int size);


int main()
{
	int wyniki[ROZMIAR], x = 0;
	int *wsk;
	wsk = wyniki;
	printf("podaj ile liczb wprowadzisz:\n");
	scanf("%d", &x);
	while (!(x < ROZMIAR)) {
		scanf("%d", &x);
	}
	printf("wprowadz liczby:\n");
	for (int i = 0; i < x; i++) {
		scanf("%d", (wsk + i));
	}
	display_vector(wyniki, x);
	reverse_vector(wyniki, x);
	display_vector(wyniki, x);

    return 0;
}

int reverse_vector(int* tab, int size){
	if (size <= 0 || tab == NULL) {
		return 0;
	}

	for (int i = 0; i < size / 2; i++) {
		int temp = *(tab + i);
		*(tab + i) = *(tab + size - 1 - i);
		*(tab + size - 1 - i) = temp;
	}
	return 1;
}

int display_vector(const int* tab, int size) {
	if (size <= 0 || tab == NULL) {
		return 0;
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", *(tab + i));
	}
	putchar('\n');
	return 1;
}