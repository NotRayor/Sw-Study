#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int *arr = NULL;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(arr) * n);

	for (int i = 0; i < n; i++)
	{
		printf("%d", arr + i);
	}

	sort(arr, arr + n);


}