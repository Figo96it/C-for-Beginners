// ConsoleApplication70.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROZMIAR 201

int subtract(const char* number1, const char* number2, char** result);
int subtract2(const char* number1, const char* number2, char* result, int com);
int add(const char* number1, const char* number2, char** result);
int add2(const char* number1, const char* number2, char* result, int k);
int validate(const char *number);
int compare(const char* number1, const char* number2);
int compare2(const char* number1, const char* number2);
int create_array2(char **ptr, int N);
void display(const char* ptr, int N);
void reverse(char *number);

int main()
{
	char *numer1 = NULL, *numer2 = NULL, *wynik = NULL;
	if (create_array2(&numer1, ROZMIAR) == 1) {
		printf("failed to allocate memory");
		return 2;
	}
	if (create_array2(&numer2, ROZMIAR) == 1) {
		free(numer1);
		printf("failed to allocate memory");
		return 2;
	}

	printf("Podaj pierwsza liczbe: ");
	fgets(numer1, ROZMIAR, stdin);
	printf("Podaj druga liczbe: ");
	fgets(numer2, ROZMIAR, stdin);
	int length1 = strlen(numer1);
	int length2 = strlen(numer2);
	
	if (*(numer1 + length1 - 1) == '\n') {
		*(numer1 + length1 - 1) = '\0';
	}
	if (*(numer2 + length2 - 1) == '\n') {
		*(numer2 + length2 - 1) = '\0';
	}

	int s = add(numer1, numer2, &wynik);
	if (s == 1 || s == 2) {
		if (numer1 != NULL) {
			free(numer1);
		}
		if (numer2 != NULL) {
			free(numer2);
		}
		if (wynik != NULL) {
			free(wynik);
		}
		printf("Error");
		return 1;
	}
	else if (s == 3) {
		if (numer1 != NULL) {
			free(numer1);
		}
		if (numer2 != NULL) {
			free(numer2);
		}
		if (wynik != NULL) {
			free(wynik);
		}
		printf("failed to allocate memory");
		return 2;
	}

	int z = subtract(numer1, numer2, &wynik);
	if (z == 1 || z == 2) {
		if (numer1 != NULL) {
			free(numer1);
		}
		if (numer2 != NULL) {
			free(numer2);
		}
		if (wynik != NULL) {
			free(wynik);
		}
		printf("Error");
		return 1;
	}
	else if (z == 3) {
		if (numer1 != NULL) {
			free(numer1);
		}
		if (numer2 != NULL) {
			free(numer2);
		}
		if (wynik != NULL) {
			free(wynik);
		}
		printf("failed to allocate memory");
		return 2;
	}
	free(numer1);
	free(numer2);
	free(wynik);
	return 0;
}

int create_array2(char **ptr, int N) {
	if (N <= 0) {
		return 1;
	}
	else if (ptr == NULL) {
		return 1;
	}

	if ((*ptr = (char*)malloc(N * sizeof(char))) == NULL) {
		return 1;
	}

	return 0;
}

int subtract(const char* number1, const char* number2, char** result) {
	if (number1 == NULL || number2 == NULL || result==NULL) {
		return 1;
	}
	if (validate(number1) != 0 || validate(number2) != 0) {
		return 2;
	}

	int length1 = strlen(number1);
	int length2 = strlen(number2);
	int comp = compare(number1, number2);
	int comp2 = compare2(number1, number2);

	if (length2 > length1) {
		length1 = length2;
	}

	if (*(number1 + 0) == '-') {
		if (*(number2 + 0) == '-') {
			if (comp == 1) {
				create_array2(result, length1 + 3);
				if (result == NULL) {
					return 3;
				}
				subtract2(number2, number1, *result, 1);
			}
			else if (comp == -1) {
				create_array2(result, length1 + 3);
				if (result == NULL) {
					return 3;
				}
				subtract2(number1, number2, *result, -1);
			}
			else if (comp == 0) {
				create_array2(result, length1 + 3);
				if (result == NULL) {
					return 3;
				}
				subtract2(number1, number2, *result, 0);
			}
		}
		else {
			create_array2(result, length1 + 3);
			if (result == NULL) {
				return 3;
			}
			add2(number2, number1, *result, -1);
		}
	}
	else {
		if (*(number2 + 0) == '-') {
			create_array2(result, length1 + 3);
			if (result == NULL) {
				return 3;
			}
			add2(number1, number2, *result, 0);
		}
		else {
			if (comp2 == 1) {
				create_array2(result, length1 + 3);
				if (result == NULL) {
					return 3;
				}
				subtract2(number1, number2, *result, 1);
			}
			else if (comp2 == -1) {
				create_array2(result, length1 + 4);
				if (result == NULL) {
					return 3;
				}
				subtract2(number2, number1, *result, -1);
			}
			else if (comp2 == 0) {
				if (create_array2(result, length1 + 3) == 1) {
					return 3;
				}
				if (result == NULL) {
					return 3;
				}
				subtract2(number1, number2, *result, 0);
			}
		}
	}

	reverse(*result);
	display(*result, length1);
	return 0;
}

int subtract2(const char* number1, const char* number2, char* result, int com) {
	int reszta = 0, x = 0, liczba1, liczba2;
	int suma = 0;
	int i = strlen(number1) - 1;
	int j = strlen(number2) - 1;
	int end1 = 0, end2 = 0;

	if (com == 0) {
		*(result + 0) = '0';
		*(result + 1) = '\0';
		return 1;
	}

	if (!(*(number1 + 0) >= '0' && *(number1 + 0) <= '9')) {
		end1 = 1;
	}

	if (!(*(number2 + 0) >= '0' && *(number2 + 0) <= '9')) {
		end2 = 1;
	}

	while (i >= end1 || j >= end2) {
		liczba1 = 0;
		liczba2 = 0;
		if (i >= end1) {
			liczba1 = *(number1 + i) - '0';
		}

		if (j >= end2) {
			liczba2 = *(number2 + j) - '0';
		}

		if (j < end2 && i < end1) {
			break;
		}

		if (reszta == 1) {
			liczba1 -= reszta;
			reszta = 0;
		}

		if (liczba1 >= liczba2) {
			suma = liczba1 - liczba2;
		}
		else {
			suma = liczba1 - liczba2 + 10;
			reszta = 1;
		}

		*(result + x) = suma + '0';
		x++;
		i--;
		j--;
	}
	x--;

	while (*(result + x) == '0') {
		*(result + x) = '\0'; 
		x--;
	}

	if (com == -1) {
		*(result + x + 1) = '-';
		*(result + x + 2) = '\0';
	}
	else {
		*(result + x + 1) = '\0';
	}

	return 1;
}

int add(const char* number1, const char* number2, char** result) {
	if (number1 == NULL || number2 == NULL || result == NULL) {
		return 1;
	}
	if (validate(number1) != 0 || validate(number2) != 0) {
		return 2;
	}
	int length1 = strlen(number1);
	int length2 = strlen(number2);
	int comp = compare2(number1, number2);

	if (*(number1 + 0) == '-') {
		if (*(number2 + 0) == '-') {
			if (length1 >= length2) {
				create_array2(result, length1 + 3);
				if (result == NULL) {
					return 3;
				}
				add2(number1, number2, *result, -1);
			}
			else {
				length1 = length2;
				create_array2(result, length1 + 3);
				if (result == NULL) {
					return 3;
				}
				add2(number1, number2, *result, -1);
			}
		}
		else {
			if (comp == 1) {
				create_array2(result, length1 + 3);
				if (result == NULL) {
					return 3;
				}
				subtract2(number1, number2, *result, -1);
			}
			else if (comp == -1) {
				length1 = length2;
				create_array2(result, length1 + 3);
				if (result == NULL) {
					return 3;
				}
				subtract2(number2, number1, *result, 1);
			}
			else if (comp == 0) {
				create_array2(result, length1 + 3);
				if (result == NULL) {
					return 3;
				}
				subtract2(number2, number1, *result, 0);
			}
		}
	}
	else {
		if (*(number2 + 0) == '-') {
			if (comp == 1) {
				create_array2(result, length1 + 3);
				if (result == NULL) {
					return 3;
				}
				subtract2(number1, number2, *result, 1);
			}
			else if (comp == -1) {
				length1 = length2;
				create_array2(result, length1 + 3);
				if (result == NULL) {
					return 3;
				}
				subtract2(number2, number1, *result, -1);
			}
			else if (comp == 0) {
				length1 = length2;
				create_array2(result, length1 + 3);
				if (result == NULL) {
					return 3;
				}
				subtract2(number1, number2, *result, 0);
			}
		}
		else {
			if (length2 > length1) {
				length1 = length2;
			}
			if (create_array2(result, length1 + 4) == 1) {
				return 3;
			}
			if (result == NULL) {
				return 3;
			}
			add2(number1, number2, *result, 0);
		}
	}
	reverse(*result);
	display(*result, length1);
	return 0;
}

int add2(const char* number1, const char* number2, char* result, int k) {
	int reszta = 0, x = 0, liczba1 = 0, liczba2 = 0;
	int suma = 0;
	int i = strlen(number1) - 1;
	int j = strlen(number2) - 1;

	int end1 = 0, end2 = 0;
	if (!(*(number2 + 0) >= '0' && *(number2 + 0) <= '9')) {
		end2 = 1;
	}
	if (!(*(number1 + 0) >= '0' && *(number1 + 0) <= '9')) {
		end1 = 1;
	}
	while (i >= end1 || j >= end2) {
		liczba1 = 0;
		liczba2 = 0;
		if (i >= end1) {
			liczba1 = *(number1 + i) - '0';
		}

		if (j >= end2) {
			liczba2 = *(number2 + j) - '0';
		}

		if (j < end2 && i < end1) {
			break;
		}

		if (reszta != 0) {
			suma = liczba1 + liczba2 + 1;
			reszta = 0;
		}
		else {
			suma = liczba1 + liczba2;
		}

		if (suma > 9) {
			reszta = 1;
			suma = suma - 10;
		}

		*(result + x) = suma + '0';
		x++;
		i--;
		j--;
	}

	if (reszta == 1) {
		*(result + x) = '1';
		if (k == -1) {
			*(result + x + 1) = '-';
			*(result + x + 2) = '\0';
		}
		else {
			*(result + x + 1) = '\0';
		}
	}
	else {
		if (k == -1) {
			*(result + x) = '-';
			*(result + x + 1) = '\0';
		}
		else {
			*(result + x) = '\0';
		}
	}

	return 1;
}

void reverse(char *number) {
	int length = strlen(number);
	for (int i = 0; i < (length) / 2; i++) {
		char t = *(number + i);
		*(number + i) = *(number + length - 1 - i);
		*(number + length - 1 - i) = t;
	}
}

int validate(const char *number) {
	if (number == NULL) {
		return 2;
	}

	int length = strlen(number)-1;
	if (length == -1) {
		return 1;

	}
	if (*(number + length) == '\n') {
		return 1;
	}

	if (!(*(number + 0) >= '1' && *(number + 0) <= '9')) {
		if (*(number + 0) == '-') {
			if (*(number + 1) == '\0'){
				return 1;
			}
		}
		if (*(number + 0) == '0' && *(number + 1) == '\0') {
			return 0;
		}
		else if (*(number + 0) == '0' && *(number + 1) != '\0')
			return 1;
	}

	for (int i = 1; i<length; i++) {
		if (!(*(number + i) >= '0' && *(number + i) <= '9')) {
			return 1;
		}
	}
	return 0;
}

int compare(const char* number1, const char* number2) {
	if (number1 == NULL || number2 == NULL) {
		return 2;
	}
	if (validate(number1) != 0 || validate(number2) != 0) {
		return 3;
	}
	int length1 = strlen(number1);
	int length2 = strlen(number2);

	if (*(number1 + 0) == '-') {
		if (*(number2 + 0) == '-') {
			if (length1 > length2) {
				return -1;
			}
			else if (length2 > length1) {
				return 1;
			}
			else {
				for (int i = 1;*(number1+i)!='\0'; i++) {
					if (*(number1 + i) > *(number2 + i)) {
						return -1;
					}
					else if (*(number2 + i) > *(number1 + i)) {
						return 1;
					} 
				}
				return 0;
			}
		}
		else {
			return -1;
		}
	}
	else {
		if (*(number2 + 0) == '-') {
			return 1;
		}
		else {
			if (length1 > length2) {
				return 1;
			}
			else if (length2 > length1) {
				return -1;
			}
			else {
				for (int i = 0;*(number1+i)!='\0'; i++) {
					if (*(number1 + i) > *(number2 + i)) {
						return 1;
					}
					else if (*(number2 + i) > *(number1 + i)) {
						return -1;
					}
				}
			}
		}
	}

	return 0;
}

int compare2(const char* number1, const char* number2) {
	int length1 = strlen(number1);
	int length2 = strlen(number2);
	int end1 = 0, end2 = 0;

	if (*(number1 + 0) == '-') {
		end1 = 1;
	}
	if (*(number2 + 0) == '-') {
		end2 = 1;
	}

	if (length1 - end1 > length2 - end2) {
		return 1;
	}
	else if (length1 - end1 < length2 - end2) {
		return -1;
	}
	else if ((length1 - end1) == (length2 - end2)) {
		for (int i = 0; i < length1; i++) {
			if (*(number1 + i + end1) > *(number2 + i + end2)) {
				return 1;
			}
			else if (*(number2 + i + end2) > *(number1 + i + end1)) {
				return -1;
			}
		}
	}
	return 0;
}

void display(const char* ptr, int N) {
	if (ptr == NULL || N <= 0) {
		return;
	}
	int i;
	for (i = 0; i<N; i++) {
		printf("%c", *(ptr + i));
	}
	printf("\n");
}