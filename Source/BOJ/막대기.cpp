#include <stdio.h>

int main()
{
	int X, stick = 64, sub, sum = 0 , count = 0;

	scanf("%d", &X);

	sum = 0;
	
	if (X == stick) {
		printf("1");
		return 0;
	}

	// ���� ���� ������ �ݺ��Ѵ�.
	while (sum != X) {
		sub = stick / 2;
		sum += sub;

		// true : ������.
		if (sum > X) {
			sum -= sub;
			stick -= sub;
		}
		else {
			count++;
		}
		
	}

	printf("%d", count);
	
}