#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int num[1001];

bool chk(int origin, int ans, int strike, int ball)
{
	int o1, o2, o3;
	int a1, a2, a3;
	int stCnt = 0;
	int bCnt = 0;

	o1 = origin / 100;
	o2 = (origin % 100) / 10;
	o3 = (origin % 100) % 10;
	
	a1 = ans / 100;
	a2 = (ans % 100) / 10;
	a3 = (ans % 100) % 10;

	if (o1 == 0 || o2 == 0 || o3 == 0 || o1 == o2 || o1 == o3 || o2 == o3)
		return 0;

	if (o1 == a1) { stCnt++; }
	if (o2 == a2) { stCnt++; }
	if (o3 == a3) { stCnt++; }

	if (o1 == a2 || o1 == a3) { bCnt++; }
	if (o2 == a1 || o2 == a3) { bCnt++; }
	if (o3 == a1 || o3 == a2) { bCnt++; }

	if (strike == stCnt && ball == bCnt)
		return 1;
	else
		return 0;
}

int main()
{
	int T;
	int ans;
	int ball;
	int strike;
	int ret = 0;

	cin >> T;


	for (int i = 0; i < T; i++)
	{
		cin >> ans >> strike >> ball;
		for (int j = 123; j <= 987; j++)
		{
			if (num[j] == 0) 
				num[j] = !chk(j, ans, strike, ball);
		}
	}

	for (int i = 123; i <= 987; i++)
	{
		if (num[i] == 0)
			ret++;
	}

	cout << ret;
}
/*
int main()
{
	int T;
	int strike;
	int ball;
	int i_one;
	int i_ten;
	int i_hundred;

	int answer[100];
	int answer_strike[100];
	int answer_ball[100];
	int answer_one[100];
	int answer_ten[100];
	int answer_hundred[100];

	
	int result = 0; 

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> answer[i];
		cin >> answer_strike[i];
		cin >> answer_ball[i];

		answer_hundred[i] = answer[i] / 100;
		answer_ten[i] = (answer[i] - (answer_hundred[i] * 100)) / 10;
		answer_one[i] = answer[i] - (answer_hundred[i] * 100) - (answer_ten[i] * 10);

	}


	for (int i = 123; i < 988; i++)
	{
		strike = 0;
		ball = 0;

		i_hundred = i / 100;
		i_ten = (i - (i_hundred * 100)) / 10;
		i_one = i - (i_hundred * 100) - (i_ten * 10);

		if (i_hundred == i_ten || i_hundred == i_one || i_ten == i_one)
			continue;

		for (int j = 0; j < T; j++)
		{
			strike = 0;
			ball = 0;

			if (answer_hundred[j] == i_hundred)
				strike++;
			if (answer_hundred[j] == i_ten)
				ball++;
			if (answer_hundred[j] == i_one)
				ball++;
			if (answer_ten[j] == i_hundred)
				ball++;
			if (answer_ten[j] == i_ten)
				strike++;
			if (answer_ten[j] == i_one)
				ball++;
			if (answer_one[j] == i_hundred)
				ball++;
			if (answer_one[j] == i_ten)
				ball++;
			if (answer_one[j] == i_one)
				strike++;

			if (answer_strike[j] != strike)
				break;
			if (answer_ball[j] != ball)
				break;

			if (j == T - 1) {
				cout << i << endl;
				result++;
			}
		}

	}

	cout << result << endl;
	
}

*/