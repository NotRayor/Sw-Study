#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	clock_t start, finish;
	double duration;
	int leng;
	double result = 1;

	start = clock(); // 실행시간 측정 코드

	printf("정수를 입력하시오. ");
	scanf("%d", &leng);

	for (int i = 1; i <= leng; i++)
		result = result * i;

	printf("%d 팩토리얼 값은 : %.1lf 입니다. \n", leng, result);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%.2lf초 입니다. \n", duration);
	
	return 0;

}