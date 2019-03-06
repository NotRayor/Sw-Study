#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	stack<char> st;
	char input;

	while ( (scanf("%c", &input ) && input != '\n') )
	{
		st.push(input);
	}

	char output;

	while ( !st.empty() )
	{
		output = st.top();
		st.pop();
		printf("%c", output);




	}




}