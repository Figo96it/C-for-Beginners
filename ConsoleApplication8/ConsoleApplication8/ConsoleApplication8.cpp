// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define ROZMIAR 100

int sum(const float* tab, unsigned int size, float *result);
int avg(const float* tab, unsigned int size, float *result);

int main()
{
	float wyniki[ROZMIAR], suma=0.0, srednia=0.0;
	float *wsk;
	wsk = wyniki;
	
	int i = 0;
	printf("Podaj liczby:\n");
	while (scanf("%f", (wsk+i)) && i < ROZMIAR){
		if ( *(wsk+i)==0) {
			break;
		}
		i++;
	}

	sum(wyniki, i, &suma);
	if (suma == 0) {
		printf("Error\n");
		return 1;
	}
	avg(wyniki, i, &srednia);
	if (srednia == 0) {
		printf("Error\n");
		return 1;
	}
	printf("Suma: %.2f\n", suma);
	printf("Srednia: %.2f", srednia);

	return 0;
}

int sum(const float* tab, unsigned int size, float *result) {
	if (tab == '\0' || result=='\0') {
		return 0;
	}else if (size < 1) {
		return 0;
	}

	float suma = 0.0;
	for(int i=0;i<(int)size;i++){
		suma += *tab;
		tab++;
	}
	*result = suma;
	return 1;
}

int avg(const float* tab, unsigned int size, float *result) {
	if (tab == '\0' || result == '\0') {
		return 0;
	}else if (size < 1) {
		return 0;
	}

	float suma=0.0, srednia = 0.0;
	for (int i = 0; i<(int)size; i++) {
		suma += *tab;
		tab++;
	}
	srednia = suma / size;
	*result = srednia;
	
	return 1;
}
