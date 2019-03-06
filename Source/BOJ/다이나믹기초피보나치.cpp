#include <stdio.h>

int dp[1001] = { 0 };

int fibonachi(int x)
{
	if (dp[x])
		return dp[x];

	dp[x] = fibonachi(x - 1) + fibonachi(x - 2);
	return dp[x];

}

int main()
{
	int N; 
	int result = 0;

	dp[1] = 1;
	dp[2] = 1;

	result = fibonachi(1000);

	printf("%d", result);
}