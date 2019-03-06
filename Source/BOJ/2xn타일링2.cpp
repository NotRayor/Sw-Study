#include <stdio.h>

int main()
{
	int dp[1001] = { 0 };
	int N;

	scanf("%d", &N);

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
		dp[i] %= 10007;
	}

	printf("%d", dp[N]);
	

}