#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b)
{
	return a > b; // 뭐 결과값이 -1이 되겠지?
}

int main()
{

	int N; // 사람의 수
	int *P = NULL; // 각 사람이 돈을 인출하는데 걸리는 시간,
	int min = 0;

	scanf("%d", &N);

	P = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", P + i );
	}

	sort(P, P + N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			min += P[j];
		}
	}
	
	printf("%d", min);
}


/*
int data[10] = { 9,3,5,7,8,1,2,4,6,10 };

sort(data, data + 10);
for (int i = 0; i < 10; i++)
{
cout << data[i] << endl;
}

sort(data, data + 10, desc);
for (int i = 0; i < 10; i++)
{
cout << data[i] << endl;
}
*/