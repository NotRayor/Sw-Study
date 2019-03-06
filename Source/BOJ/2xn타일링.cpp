#include <stdio.h>

int dp[1000] = { 0 };

int main()
{
	int N; // 2 x N 크기의 직사각형을 채우는 방법의 수,
	// 직사각형은 1x2, 2x1 타일로만 채울 수 있다.

	scanf("%d", &N);

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}

	printf("%d", dp[N]);
}