// ConsoleApplication17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main()
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";
	int i = 0;
	while (*(t1+i) != '\0') {
		putchar(*(t1+i));
		i++;
	}
    return 0;
}

