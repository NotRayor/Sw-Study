#include <stdio.h>
#include <algorithm>

int price[11] = { 0, 1, 5, 8, 9,
		10, 17, 17, 20, 24,
		30 };

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int val[100] = { };

// p 자르는 막대기 가격, n 자르는 막대기 크기, 
int cutRod(int p, int n) {

	// j는 자르는 막대기  맨 아래부터 최적화된 자른 값들을 구한다.
	for (int j = 1; j <= n; j++) {
		int q = -1;

		for (int i = 0; i <= j; i++) {
			q = max(q , price[i] + val[j - i]);
		}
		val[j] = q;
	}
	return val[n];
}

int main()
{
	int n; // 가진 막대기 크기

	scanf("%d", &n);

	printf("%d", cutRod(0, n));
	
}