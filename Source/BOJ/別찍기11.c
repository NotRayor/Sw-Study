#include <stdio.h>

int star(int);

int main()
{
	int N; // NÀº 3, 6, 12, 24, 48 ... 3*2^k

	scanf(" %d", &N);

	star(N);


}

int star(int st)
{
	int i, j, k;

	for (i = 0; i < st; i++)
	{
		for (j = 0; j < st * 2; j++)
		{
			if ( st - i <= j && j <= )
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}

}