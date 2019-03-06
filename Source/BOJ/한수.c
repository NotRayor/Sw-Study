#include <stdio.h>

int main()
{
	int X;
	int cnt = 0;
	int i = 0;
	int a, b, c;

	scanf(" %d", &X);
	
	if (X < 100)
	{
		printf("%d", X);
	}
	else
	{
		cnt = 99;
		for (i = 100; i <= X; i++)
		{
			a = i / 100;
			b = (i % 100) / 10;
			c = i % 10;
			
			if ((a - b) == (b - c))
				cnt++;

		}
		printf("%d", cnt);
	}
	return 0;
}

// 이프 엘스로 이쁘게 딱딱 구분했어야 했다.. 
// 그리고 무엇보다 한수는 99이하의 모든 수 라는 더러운 허점;;