#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>

#define MAX 100

using namespace std;

int sum = 0; // 7명의 난쟁이들의 합이 100일때 정답이다.

void getSum(int *arr)
{
	for (int i = 0; i < 9; i++)
	{
		sum += arr[i];
	}
}

int solution(int *arr)
{
	int ans;

	for (int i = 0; i <= 7; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			ans = sum;
			if (i == j) { continue; }
			if (ans - arr[i] - arr[j] == MAX)
			{
				arr[i] = -1;
				arr[j] = -1;
				return 1;
			}
		}
	}
}

int main()
{
	int ans = 0;
	int dwarf[9] = { 0 };

	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
	}

	getSum(dwarf);
	sort(dwarf, dwarf + 9, less<int>());
	solution(dwarf);


	for (int i = 0; i <= 8; i++)
	{
		if (dwarf[i] != -1)
			cout << dwarf[i] << endl;
	}
}


/*
#define MAX 100

using namespace std;

int getSum(int *arr)
{
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int solution(int *arr)
{
	int sum = getSum(arr);

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == MAX)
			{
				arr[i] = -1;
				arr[j] = -1;
				return 1;
			}
		}
	}
	return -1;
}

int main()
{
	int drawf[9];
	for (int i = 0; i < 9; i++)
		cin >> drawf[i];

	solution(drawf);

	sort(drawf, drawf + 9, less<int>());


	for (int i= 2; i < 9; i++)
	{
		printf("%d \n", drawf[i]);
	}
}
*/

/*
	vector<int> drawf;

	int a = 2;
	int b = 10;

	int sum = 0;
	int temp = 0;

	int height = 0;
	int count = 0;
	
	vector<int>::iterator iter;
	vector<int>::iterator iter2;


	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &height);
		drawf.push_back(height);
		sum += height;
	}
	

	for (iter = drawf.begin(); iter != drawf.end(); iter++)
	{
		temp = sum;
		temp -= *iter;
		for (iter2 = next(iter,1); iter2 != drawf.end(); iter2++)
		{
			temp -= *iter2;
			if (temp == 100) {
				drawf.erase(iter2); // 없어져야할 난쟁이
				break;
			}
			temp += *iter2; // 아닌 경우 복구!
		}
		if (temp == 100) {
			drawf.erase(iter); // 없어져야할 난쟁이
			break;
		}
		temp += *iter;
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (drawf[i] > drawf[j])
			{
				swap(drawf[i], drawf[j]);
			}
		}
	}

	for(int i = 0; i < 7; i++)
		printf("%d \n", drawf[i]);
*/