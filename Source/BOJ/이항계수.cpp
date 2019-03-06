#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>


using namespace std;

// nCr 
// ( n )
// ( r  )
// n! / r!(n-r)!

int dp[1001] = { -1 };

int factorial(int n)
{
	if (dp[n] != -1)
		return dp[n];

	return n * factorial(n - 1);
}

int main()
{
	int N, K;

	scanf("%d %d", &N, &K);

	fill(dp, dp + 1000, -1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 0; i <= N; i++)
	{
		dp[i] = factorial(i);
		dp[i] %= 10007;
	}

	int result = factorial(N) / ( factorial(K) * factorial(N - K) );
	printf("%d", result % 10007);

}