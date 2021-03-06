// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

#define ROZMIAR 100
#define STOP -1
int read_vector(int* tab, int size, int stop_value);
void display_vector(const int* tab, int size);
int sort(int* tab, int size);

int main()
{
	int wyniki[ROZMIAR];

	int rozmiar=read_vector(wyniki, ROZMIAR, STOP);
	sort(wyniki, rozmiar);
	display_vector(wyniki, rozmiar);

    return 0;
}

int read_vector(int* tab, int size, int stop_value) {
	printf("Wpisuj wartosci calkowite\n");

	int i = 0;
	while (scanf("%d",(tab + i)) && i<size) {
		if (*(tab + i) == stop_value) {
			break;
		}
		i++;
	}
	size = i-1;
	return size;
}

void display_vector(const int* tab, int size) {
	for (int i = 0; i <= size; i++) {
		printf("%d ", *(tab + i));
	}
	putchar('\n');
}

int sort(int* tab, int size) {
	if (tab == '\0') {
		return 0;
	}else if (size < 1) {
		return 1;
	}
	else if (size < 2) {
		if (*tab > *(tab + 1)) {
			int t = *tab;
			*tab = *(tab + 1);
			*(tab + 1) = t;
		}
		return 1;
	}

	int zmiana, i;
	do {
		zmiana = 0;
		i = size;
		do {
			i--;
			if (*(tab + i) > *(tab + i + 1)) {
				int t = *(tab+i);
				*(tab + i) = *(tab + i + 1);
				*(tab + i + 1) = t;
				zmiana=1;
			}
		} while (i != 0);
	} while (zmiana != 0);


	return 1;
}


