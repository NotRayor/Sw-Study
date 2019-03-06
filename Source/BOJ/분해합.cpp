#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000000


using namespace std;

int main()
{
	int n[7] = { 0 };
	int N;
	int number;
	scanf("%d", &N);

	for (int i = 0; i <= MAX_SIZE; i++)
	{
		int createrNumber = 0;
		number = i;
		while (number != 0)
		{
			int rest = number % 10;
			createrNumber += rest;
			number /= 10;
		}
		createrNumber += i;

		if (N == createrNumber) {
			printf("%d", i);
			break;
		}
		if (i + 1 > MAX_SIZE)
		{
			cout << "0" << "\n";
			break;
		}
	}


}