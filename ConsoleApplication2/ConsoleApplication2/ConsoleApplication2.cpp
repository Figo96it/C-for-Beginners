// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main()
{
	int a = 1, *wsk;
	wsk = &a;
	printf("%d %d %p\n", a, *wsk, (void*)wsk);
	*wsk = 5;
	printf("%d %d %p", a, *wsk, (void*)wsk);
	return 0;
}

