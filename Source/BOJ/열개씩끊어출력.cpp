#include <stdio.h>
#include <string.h>

int main()
{
	char str[102];
	int i = 0, j, leng;

	scanf("%s", str);
	leng = strlen(str);
	
	for (i = 0; i < leng; i++)
	{
		printf("%c", str[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}

}