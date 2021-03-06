#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROZMIAR 1010
#define ROZMIAR2 2020
char* my_strcpy(char* dest, const char* src);
char* my_strcat(char* dest, const char* src);
int my_strlen(const char* str);

int main()
{
	char tekst[ROZMIAR2], tekst2[ROZMIAR];
	printf("nap: ");
	fgets(tekst, ROZMIAR2, stdin);
	printf("nap: ");
	fgets(tekst2, ROZMIAR, stdin);
	int l1 = my_strlen(tekst);
	int l2 = my_strlen(tekst2);

	printf("%d %d", l1 - 1, l2 - 1);
	putchar('\n');

	*(tekst + l1 - 1) = '\0';
	*(tekst2 + l2 - 1) = '\0';

	my_strcpy(tekst, tekst2);
	puts(tekst);
	/*for (int i = 0; *(tekst + i) != '\0'; i++) {
	putchar(*(tekst + i));
	}*/

	my_strcat(tekst, tekst2);
	for (int x = 0; *(tekst + x) != '\0'; x++) {
		putchar(*(tekst + x));
	}

	return 0;
}

char* my_strcpy(char* dest, const char* src) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	int i;
	for (i = 0; *(src + i) != '\0'; i++) {
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';

	return dest;
}

char* my_strcat(char* dest, const char* src) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}

	int l1 = my_strlen(dest);
	int i;
	for (i = l1; *(src + i - l1) != '\0'; i++) {
		*(dest + i) = *(src + i - l1);
	}
	*(dest + i) = '\0';

	return dest;
}


int my_strlen(const char* str) {
	if (str == NULL) {
		return -1;
	}

	int i = 0;
	for (; *(str + i) != '\0'; i++);
	return i;
}
