#include <stdio.h>
#include <string.h>

int main()
{
	char S[101];

	fgets(S, 101, stdin);
	int length = strlen(S);
	

	// a bcdefghijklmnopqrstu
	for (int i = 0; i < length; i++)
	{
		if (S[i] == ' ')
			continue;
		if (('a' <= S[i] && S[i] <= 'm') || ('A'<= S[i] && S[i] <= 'M') ) 
		{
			S[i] += 13;
		}
		else if (('n' <= S[i] && S[i] <= 'z' )||( 'N' <= S[i] && S[i] <= 'Z' ))
		{
			S[i] -= 13;
		}

	}

	printf("%s\n", S);
}

/*

printf("%c", 'm' + 13); // 결과 z 즉, m까지는 허용,
printf("%c", 'n' - 13);
// n >> a

*/