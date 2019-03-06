#include <stdio.h>

int dp[1000] = { 0 };

int main()
{
	int N; // 2 x N ũ���� ���簢���� ä��� ����� ��,
	// ���簢���� 1x2, 2x1 Ÿ�Ϸθ� ä�� �� �ִ�.

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