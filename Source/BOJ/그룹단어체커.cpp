#include <stdio.h>
#include <cstring>


int main()
{
	int N; // 단어의 개수,
	int isGroup = 1;
	int count = 0; // 그룹단어의 갯수,
	char group[101];
	char alpha[26] = { 0 };
	char check[26] = { 0 };
	int j;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", group);
		isGroup = 1;

		for (j = 0; j < strlen(group) - 1; j++)
		{
			if (group[j] == group[j+1])
				check[group[j] - 'a'] += 1;

			alpha[group[j] - 'a'] += 1; // 알파벳 갯수 
		}
		alpha[group[j] - 'a'] += 1;

		for ( j = 0; j < 26; j++)
		{
			if (alpha[j] == 0)
				continue;

			if (alpha[j] - 1 != check[j])
				isGroup = 0;

			alpha[j] = 0; // 다음을 위해서 초기화 해주자.
			check[j] = 0;
		}
		if (isGroup == 1)
			count++;
	}
	
	printf("%d", count);
}