#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

/*
int make(int x)
{
	if (dp[x])
		return dp[x];

	if (x % 3 == 0)
	{
		dp[x] = make(x/3) + make(3);
		return dp[x];
	}
	if (x % 2 != 0 && x % 3 != 0) {
		dp[x] = make(1) + make(x - 1);
		return dp[x];
	}
	if (x % 2 == 0)
	{
		dp[x] = make(x / 2) + make(3);
		return dp[x];
	}

}
*/

int main()
{
	const int MAX = 10000001;
	int N;
	int *dp = (int*)malloc(sizeof(int) * MAX);
	fill(dp, dp + MAX, 100000); // 모든 dp에 매우 큰값을 채운다.
	
	scanf("%d", &N);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 0; i < N; i++)
	{
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if(i*2 < MAX)
			dp[i * 2] = min(dp[i * 2], dp[i] + 1);
		if(i*3 < MAX)
			dp[i * 3] = min(dp[i * 3], dp[i] + 1);
	}

	printf("%d", dp[N]);

}