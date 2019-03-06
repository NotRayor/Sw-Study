#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

	int left, right, mid;
	int N, M;
	int i;

	int *arr1 = NULL;
	int *arr2 = NULL;

	
	scanf("%d", &N);
	arr1 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr1 + i);
	}

	scanf("%d", &M);
	arr2 = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", arr2 + i);
	}

	sort(arr1, arr1 + N);

	i = 0;
	while (i < M)
	{
		left = 0;
		right = N - 1;
		int result = 0;

		while (left <= right)
		{
			mid = (left + right) / 2;
			if (arr2[i] < arr1[mid])
			{
				right = mid - 1;
			}
			else if (arr2[i] > arr1[mid])
			{
				left = mid + 1;
			}
			else
			{
				result = 1;
				break;
			}
		}

		i++;
		printf("%d \n", result);
	}
}


/*
//이진탐색진행
int left;
int right;
int result = 0;
int num = 8; // 찾는값

int A[10] = { 5,4,2,10,9,8,1,3,6,7 };
//이분탐색전 정렬이 되어있어야한다.

sort(A, A + 10);
left = 0; right = 9;

while (left <= right)
{
int mid = ( left + right) / 2;
if (A[mid] > num)
right = mid - 1;
else if (A[mid] < num)
left = mid + 1;
else
{
result = mid;
break;
}
}
printf("%d", A[result]);
*/