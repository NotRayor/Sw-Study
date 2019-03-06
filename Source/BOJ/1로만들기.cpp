#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>

const int MAX = 1000001;

using namespace std;

int main()
{
	//int dp[MAX]; // �ε����� N, dp�� ���� �ּ� ����Ƚ��
	int *dp = (int*)malloc(sizeof(int) * MAX);
	int result;
	int N; 

	scanf("%d", &N);

	fill(dp, dp + MAX, 10000000); // dp�� �ſ� ū ���� ä��, ����Ѱ� ������ �ּҰ����� ������Ų��.

	dp[1] = 0; //N = 1 �϶� ����Ƚ�� 0

	// dp[i]�� ������������ dp[i-1]+1, dp[i/2]+1, dp[i/3]+1 �� �ּڰ��� ���������� ��
	for (int i = 1; i < N; i++)
	{
		dp[i + 1] = min(dp[i + 1], dp[i] + 1); // ex. ���� 2�϶� -1�� ����Ƚ�� 1 �������ϱ�, + 1
		if (i * 2 < MAX)
			 dp[i * 2] = min(dp[i * 2], dp[i] + 1); // 
		if (i * 3 < MAX)
			 dp[i * 3] = min(dp[i * 3], dp[i] + 1); // dp[i*3]�� ���Ǿ��ְų� dp[i] + 1 ( �����ѹ� ��, �׳� 3���� ������ �� ���� �� ��� )
	}
	printf("%d", dp[N]);
}


/* ž�ٿ�

int dp[MAX];

int f(int n)
{
	if (n == 1)
		return 0;
	if (dp[n] != -1) // dp[n] = 0�� �ƴ� ���, �̹� ���� ��
	{
		return dp[n];
	}

	int result = f(n - 1) + 1;

	if (n % 3 == 0) // 3�� ���
	{
		result = min(result, f(n / 3) + 1); // f(n/3) + 1 �� result �߿��� �ּҰ��� �� ������� �ִ´�.
	}
	if (n % 2 == 0) // 2�� ���
	{
		result = min(result, f(n / 2) + 1);
	}
	dp[n] = result;
	
	return dp[n];
}

int main()
{
	int N; // �־����� ����
	scanf("%d", &N);

	fill(dp, dp + MAX, -1); // �迭 dp�� ���dp + MAX����,  -1�� �ʱ�ȭ�Ѵ�.

	printf("%d", f(N));
}

*/