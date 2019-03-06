#include <stdio.h>

int main()
{
	int num[100001];
	int n;

	scanf("%d", &n);

	while (n > 1)
	{
		for (int i = 1; i <= n; i++)
		{
			num[i] = i;
			printf("%d ", i);
		}
		printf("\n");

		if (n % 2 == 1)
			n++;
		n /= 2;
	}
}