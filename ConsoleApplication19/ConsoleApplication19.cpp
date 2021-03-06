// ConsoleApplication19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace);

int main()
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";
	int male_lit, duze_lit, znaki_spec;
	marks_counter(t1, &male_lit, &duze_lit, &znaki_spec);
	printf("%d %d %d",male_lit,duze_lit,znaki_spec);
	return 0;
}

int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace) {
	if (text == NULL) {
		return -1;
	}
	else if(uppercase == NULL || lowercase == NULL || whitespace == NULL) {
		return -2;
	}
	int duze = 0, male = 0, znaki = 0;
	for (int i = 0; *(text + i); i++) {
		if (*(text + i) >= 'A' && *(text + i) <= 'Z') {
			duze++;
		}
		else if (*(text + i) >= 'a' && *(text + i) <= 'z') {
			male++;
		}
		else if (*(text + i) == ' ') {
			znaki++;
		}
	}
	*uppercase = duze;
	*lowercase = male;
	*whitespace = znaki;
	return 1;
}