#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>



int main()
{
	char str[101];
	char *ptr = NULL;
	char sstr[51];

	scanf("%s", str);
	ptr = strtok(str, "-");

	while (ptr != NULL)
	{
		printf("%c", ptr[0]);
		ptr = strtok(NULL, "-");
	}

}

/*
char s1[30] = "The Little Prince";
char *ptr = strtok(s1, " ");

printf("%s \n", ptr);

while (ptr != NULL)
{
printf("%s \n", ptr);
ptr = strtok(NULL, " "); // NULL�� ��쿡�� ������ ó���ߴ� ���ڿ����� �߸� ���ڿ� ��ŭ ���� ���ڷ� �̵��� �� ���� ���ڿ� �ڸ�,
}

���� �������� ���ڿ� �и��ϴ� �Լ�, strtok(s1, " ");

return 0;

*/