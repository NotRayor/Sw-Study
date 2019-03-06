#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	int **arr = NULL;
	arr = (int **)malloc(sizeof(int *) * M);

	for (int i = 0; i < M; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = j + 1;
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	while (M > 0)
	{
		for (int i = 1; i <= N; i++)
		{
			printf("%d", i);
		}
		M++;
	}

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			for (int z = 1; z <= 3; z++)
			{
				printf("%d %d %d \n", i, j, z);
			}
		}
	}


}