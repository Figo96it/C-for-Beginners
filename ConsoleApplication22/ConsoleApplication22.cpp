// ConsoleApplication22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROZMIAR 1010
char* my_strcpy(char* dest, const char* src);
char* my_strcat(char* dest, const char* src);
int my_strlen(const char* str);

int main()
{
	char tekst[ROZMIAR], tekst2[ROZMIAR];
	printf("nap: ");
	int i = 0;
	while (*(tekst=getchar() && ) {
		i++;
		while (scanf("%s", (tekst + i)) && *(tekst + i) != '\0') {
			i++;
		}
	}
	printf("nap: ");
	fgets(tekst, ROZMIAR, stdin);

	my_strcpy(tekst, tekst2);
	for(int i=0;*(tekst + i)!='\0';i++){
		putchar(*(tekst + i));
	}
	
	for (i = 0; *(tekst + i)!='\0'; i++) {
		putchar(*(tekst + i));
	}
	getchar();
    return 0;
}

char* my_strcpy(char* dest, const char* src) {
	int l1 = my_strlen(dest);
	int l2 = my_strlen(src);
	int rozmiar = l1 + l2;
	dest = (char*)malloc(rozmiar * sizeof(char));
	char* p=dest;

 while (*dest) dest++;      /* przejdź na koniec łańcucha docelowego */
 while (*dest++ = *src++);  /* dołącz łańcuch źródłowy */

 return p;
}

char* my_strcat(char* dest, const char* src) {
	int l1 = my_strlen(dest);
	int l2 = my_strlen(src);
	for (int i = l1; i < l2; i++) {
		*(dest + i) = *(src + i - l1);
	}
	return dest;
}


int my_strlen(const char* str) {
	int i = 0;
	for (; *(str + i) != '\0'; i++);
	return i;
}

