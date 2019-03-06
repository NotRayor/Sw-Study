#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>

const int MAX = 1000001;

using namespace std;

int main()
{
	//int dp[MAX]; // 인덱스는 N, dp의 값은 최소 연산횟수
	int *dp = (int*)malloc(sizeof(int) * MAX);
	int result;
	int N; 

	scanf("%d", &N);

	fill(dp, dp + MAX, 10000000); // dp에 매우 큰 값을 채워, 계산한걸 무조건 최소값으로 지정시킨다.

	dp[1] = 0; //N = 1 일때 연산횟수 0

	// dp[i]에 도달했을때는 dp[i-1]+1, dp[i/2]+1, dp[i/3]+1 중 최솟값이 구해져있을 것
	for (int i = 1; i < N; i++)
	{
		dp[i + 1] = min(dp[i + 1], dp[i] + 1); // ex. 값이 2일때 -1로 연산횟수 1 더해지니까, + 1
		if (i * 2 < MAX)
			 dp[i * 2] = min(dp[i * 2], dp[i] + 1); // 
		if (i * 3 < MAX)
			 dp[i * 3] = min(dp[i * 3], dp[i] + 1); // dp[i*3]이 계산되어있거나 dp[i] + 1 ( 연산한번 함, 그냥 3으로 나눠서 이 값이 된 경우 )
	}
	printf("%d", dp[N]);
}


/* 탑다운

int dp[MAX];

int f(int n)
{
	if (n == 1)
		return 0;
	if (dp[n] != -1) // dp[n] = 0이 아닐 경우, 이미 계산된 것
	{
		return dp[n];
	}

	int result = f(n - 1) + 1;

	if (n % 3 == 0) // 3의 배수
	{
		result = min(result, f(n / 3) + 1); // f(n/3) + 1 과 result 중에서 최소값인 걸 결과값에 넣는다.
	}
	if (n % 2 == 0) // 2의 배수
	{
		result = min(result, f(n / 2) + 1);
	}
	dp[n] = result;
	
	return dp[n];
}

int main()
{
	int N; // 주어지는 정수
	scanf("%d", &N);

	fill(dp, dp + MAX, -1); // 배열 dp를 요소dp + MAX까지,  -1로 초기화한다.

	printf("%d", f(N));
}

*/