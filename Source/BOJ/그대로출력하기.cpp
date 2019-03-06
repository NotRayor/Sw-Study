#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	char a;
	a = getchar();

	while (a != EOF)
	{
		putchar(a);
		a = getchar();
	}
}