// Clamp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int clamp(int *v, int lo, int hi);

int main()
{
	int a, dol, gora, *wsa;
	wsa = &a;

	printf("Podaj liczbe: ");
	scanf("%d", wsa);
	putchar('\n');
	printf("Podaj pierwsza granice: ");
	scanf("%d", &dol);
	putchar('\n');
	printf("Podaj druga granice: ");
	scanf("%d", &gora);
	putchar('\n');

	clamp(wsa, dol, gora);
	printf("%d", *wsa);

    return 0;
}

int clamp(int *v, int lo, int hi) {
	if (v == NULL) {
		return 0;
	}
	else if (lo > hi) {
		int t = lo;
		lo = hi;
		hi = t;
	}
	
	if (*v < lo) {
		*v = lo;
	}
	else if (*v > hi) {
		*v = hi;
	}

	return 1;
}

