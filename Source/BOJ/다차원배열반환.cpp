#include <stdio.h>
#include <iostream>

using namespace std;

char arr[20] = { 1 };
char arr2[4][5] = { 10 };
//1차원 배열 반환
char *func(void)
{
	return arr;
}

char (*func2())[5]
{
	return arr2;
}

int main()
{
	char *array;
	array = func();

	printf("%d", array[0]);

	char (*array2)[5];
	array2 = func2();

	printf("%d", array2[0]);

}