// ConsoleApplication21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>


int main()
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";
	int length = strlen(t1);
	for (int i = length-1; i >= 0; i--) {
		putchar(*(t1 + i));
	}
	return 0;
}

