// ConsoleApplication20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";
	
	for (int i = 0; *(t1 + i) != ' '; i++) {
		putchar(*(t1 + i));
	}

	return 0;
}

