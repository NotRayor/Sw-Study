#include <stdio.h>

int main()
{
	long long int dp[36] = { 0 };
	int n;

	scanf("%d", &n);
	
	dp[0] = 1;


	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i] += dp[j] * dp[i - (j + 1)];
		}
	}

	printf("%lld", dp[n]);


}