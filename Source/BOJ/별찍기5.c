#include<stdio.h>

int main() {
	int j, n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}

}


/*
int main() {
	int i, j;
	int n;
	int a;

	scanf("%d", &n);
	
	a = n;
	
	for (; n > 0; n--)
	{
		for (i = n; i < a; i++) {
			printf(" ");
		}
		for (i = 0; i < n*2 -1; i++) {
			printf("*");
		}
		printf("\n");
	}
	n = a - 1;
	for (i = 1; i <= n; i++)
	{
		for (j = i; j <= n - 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j <= i * 2; j++) {
			printf("*");
		}
		printf("\n");
	}
}
*/



/*
int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i - 1; j++) {
			printf("*");
		}
		for (int j = i; j < n ; j++) {
			printf(" ");
		}

		for (int j = 0; j < n - i; j++) {
			printf(" ");
		}
		for (int j = 0; j <= i-1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j <= i-1; j++) {
			printf("*");
		}
		for (int j = i; j <= n - 1; j++) {
			printf(" ");
		}
		for (int j = i; j <= n - 1; j++) {
			printf(" ");
		}
		for (int j = 0; j <= i - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
}
*/




/*
int main() {
	int i;
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j < n; j++) {
			printf(" ");
		}
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = i; j < n; j++)
		{
			printf(" ");
		}
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
*/

/*
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j<n; j++) printf(" ");
		for (int j = 1; j <= 2 * i - 1; j++) printf("*");
		printf("\n");
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i; j<n; j++) printf(" ");
		for (int j = 1; j <= 2 * i - 1; j++) printf("*");
		printf("\n");
	}
}
*/

/*
다이아몬드 형 별찍기, 5,6을 응용해서 풀어야한다.
2*N-1번째 줄 까지 차례대로 별 출력,
*/
/*
int main()
{
	int N;
	int N2 = 1;
	int i, j;
	int d = 0;

	scanf(" %d", &N);

	for (i = 1; i <= N; i++) {
		for (j = 1; j < N + i; j++) {
			if (N - i < j)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	for (i =N; i <= 2 * N - 1; i++)
	{
		d += 2;
		for (j = 0; j < (N + i) - d; j++)
		{
			if (i - N < j)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
*/



/*
별찍기 6
// 맨 위에는 N*2 - 1개의 별, 그 아래 줄부터는 N*2 - 3, N*2 - 5 이런 식으로 찍히는 패턴, 별은 중앙에 모여야한다.
int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N * 2 - i; j++)
		{
			if (i <= j)
				printf("*");
			else
				printf(" ");

		}
		printf("\n");
	}
}
*/








/*
#include <stdio.h>

int main()
{
	int N;
	int i, j;
	int leng = 0;

	scanf(" %d", &N);

	leng = N / 2;

	for (i = 0; i <= N; i++)
	{
		for (j = 1; j <= N + i;  j++) 
		{
			if (N - i <= j && j <= N + i)	
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
*/