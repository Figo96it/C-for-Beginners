// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main()
{
	int a = 5;
	int *pti = &a;
	float b = 2.4;
	float *ptf= &b;
	char c = '$';
	char *ptc = &c;

	*pti = 14;
	*ptf = 20.2;
	*ptc = '#';

	printf("%d %.1f %c", *pti, *ptf, *ptc);

	return 0;

}

