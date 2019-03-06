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
ptr = strtok(NULL, " "); // NULL일 경우에는 직전에 처리했던 문자열에서 잘린 문자열 만큼 다음 문자로 이동한 뒤 다음 문자열 자름,
}

문자 기준으로 문자열 분리하는 함수, strtok(s1, " ");

return 0;

*/