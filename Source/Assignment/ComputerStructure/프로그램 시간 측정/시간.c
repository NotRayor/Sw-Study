#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	clock_t start, finish;
	double duration;
	int leng;
	double result = 1;

	start = clock(); // ����ð� ���� �ڵ�

	printf("������ �Է��Ͻÿ�. ");
	scanf("%d", &leng);

	for (int i = 1; i <= leng; i++)
		result = result * i;

	printf("%d ���丮�� ���� : %.1lf �Դϴ�. \n", leng, result);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%.2lf�� �Դϴ�. \n", duration);
	
	return 0;

}