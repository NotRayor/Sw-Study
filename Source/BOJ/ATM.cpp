#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b)
{
	return a > b; // �� ������� -1�� �ǰ���?
}

int main()
{

	int N; // ����� ��
	int *P = NULL; // �� ����� ���� �����ϴµ� �ɸ��� �ð�,
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