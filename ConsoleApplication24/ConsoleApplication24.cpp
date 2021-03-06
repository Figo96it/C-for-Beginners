// ConsoleApplication24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROZMIAR 1010
int swap_order_words(char* text);
void ReverseInPlace(char *pstart, char *pend);

int main()
{
	char tekst[ROZMIAR];
	printf("nap: ");
	fgets(tekst, ROZMIAR, stdin);
	int length = strlen(tekst);
	*(tekst + length-1) = '\0';
	swap_order_words(tekst);
	printf("%s", tekst);

    return 0;
}

int swap_order_words(char* text) {
	if (text == NULL) {
		return 0;
	}
	
	int x = strlen(text);
	for (int i = 0; i< x / 2; i++) {
		int temp = *(text + i);
		*(text + i) = *(text + x - 1 - i);
		*(text + x - 1 - i) = temp;
	}
	
	char *pstart;
	char *pend;
	pstart = text;

	while (*pstart != '\0') {
		while (*pstart == ' ') {
			pstart++;
		}
		pend = pstart;

		while (*pend != ' ' && *pend != '\0') {
			pend++;
		}

		if (pstart > pend - 1)
			return 0;

		ReverseInPlace(pstart, pend-1);
		pstart = pend;
	}
	return 1;
}

void ReverseInPlace(char *pstart, char *pend) {
	if (pstart == pend) {
		return;
	}
	char tmp;
	while (pend > pstart) {
		tmp = *pstart;
		*pstart++ = *pend;
		*pend-- = tmp;
	}
}