// ConsoleApplication18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#define ROZMIAR 1010

int ASCIIZ_length(const char* txt);

int main()
{
	char tekst[ROZMIAR];
	const char* wsktekst = tekst;
	int length = 0;
	printf("Pisz:\n");
	fgets(tekst, ROZMIAR, stdin);
	length = ASCIIZ_length(wsktekst)-1;
	printf("Size : %d", length);
    return 0;
}

int ASCIIZ_length(const char* txt) {
	if (txt == NULL) {
		return -1;
	}
	else if (*txt == '\n') {
		return 1;
	}

	int i=0;
	while (*(txt + i) != '\0') {
		i++;
	}
	int length = i;
	if (length == 0) {
		return 0;
	}
	else if (length < 0) {
		return 1;
	}
	return length;
}