// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

#define ROZMIAR 10

int main()
{
	int t[ROZMIAR];
	int *wsk;
	wsk = t;
	for (int i = 0; wsk < t + ROZMIAR; i++) {
		*wsk = i;
		wsk++;
	}

	for (wsk = t; wsk < t+ROZMIAR; wsk++) {
		printf("%d ", *wsk);
	}
	return 0;
}

