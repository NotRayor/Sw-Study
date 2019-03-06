#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N; //  2 ~ N 범위 지정
	int K; // K번째 지워진 수,
	int num[1001] = { 0 };
	int *erase = NULL;
	int cnt = 0;

	scanf("%d %d", &N, &K);
	erase = (int*)calloc(N + 1, sizeof(int));

	for (int i = 2; i <= N; i++)
	{
		if (num[i] == 0)
		{
			for (int j = i; j <= N; j += i)
			{
				if (num[j] == 0)
				{
					num[j] = 1;
					erase[cnt++] = j;
				}
			}
		}
	}

	printf("%d ", erase[K - 1]);
}