#include <stdio.h>

int main()
{
	int T; // 테스트 케이스
	int k, n; // k는 층수, n은 호실
	int array[15][14] = { 0 };
	int sum = 0;

	scanf(" %d", &T);

	while (T != 0) {

		for (int i = 1; i <= 14; i++)
		{
			array[0][i - 1] = i;
		}

		for (int i = 1; i < 15; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				for (int z = 0; z <= j; z++)
				{
					sum += array[i - 1][z];
				}
				array[i][j] = sum;
				sum = 0;
			}
		}


		scanf(" %d", &k);
		scanf(" %d", &n);

		printf("%d \n", array[k][n - 1]);
		T--;
	}
}
	
/*
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 14; j++) {
			printf(" %d", array[i][j]);
		}
		printf("\n");
	}
	*/


	
