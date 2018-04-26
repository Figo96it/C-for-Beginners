// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define ROZMIAR 100

int tab_min(const int* tab, int size, int *min);

int main()
{
	int wyniki[ROZMIAR], x = 0, min = *wyniki;
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
		
	tab_min(wyniki, x, &min);
	printf("Min: %d", min);

    return 0;
}

int tab_min(const int* tab, int size, int *min) {
	if (size < 0 || tab==NULL || min==NULL) {
		return 0;
	}
	int minimum = *tab;
	for (int i = 0; i < size; i++) {
		if (*(tab+i) < minimum) {
			minimum = *(tab+i);
		}
	}
	*min = minimum;
	return 1;
}


