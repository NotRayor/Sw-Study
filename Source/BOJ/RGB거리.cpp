#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	long long int arr[1001][3];
	long long int dp[1001][3] = { 0 };
	int N; // ÁýÀÇ °¹¼ö,

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i][0]);
		scanf("%lld", &arr[i][1]);
		scanf("%lld", &arr[i][2]);
	}

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = arr[i][2] + min(dp[i - 1][1], dp[i - 1][0]);
	}

	printf("%lld", min(min(dp[N-1][0],dp[N-1][1]), dp[N-1][2]));

}