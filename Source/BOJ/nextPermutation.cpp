#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;


int main()
{
	int N = 0;
	vector<int> v;

	scanf("%d", &N);

	
	for (int i = 0; i < N; i++)
	{
		v.push_back(i + 1);
	}

	do {
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");

	} while (next_permutation(v.begin(), v.end()));
	


}