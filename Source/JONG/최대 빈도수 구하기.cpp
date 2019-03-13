#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;


// 인자값에 const를 붙이는 이유는? 상수인데.. 값을 추가하지 않으려는 건가 >> 정답
int majority(const vector<int>& A)
{
	int N = A.size();
	int majority = -1, majorityCount = 0;
	for (int i = 0; i < N; i++)
	{
		// A에 등장하는 A[i]의 수를 센다.
		int V = A[i], count = 0;
		for (int j = 0; j < N; j++){
			if (A[j] == V) {
				count++;
			}
		}
		if (count > majorityCount) {
			majorityCount = count;
			majority = V;
		}
	}
	// 가장 최대 빈도의 수
	return majority;
}

// 사실 중간고사 점수였고, 0~100까지 구분하기,
int majority2(const vector<int>& A)
{
	int N = A.size();
	vector<int> count(101, 0);
	for (int i = 0; i < N; i++)
	{
		count[A[i]]++;
	}
	
	int majority = 0;
	for (int i = 0; i <= 100; i++)
	{
		if (count[i] > count[majority])
		{
			majority = i;
		}
	}

	return majority;
}

int main()
{
	vector<int> Array;
	srand(time(NULL));
	int result = 0;

	
	for (int i = 0; i < 20; i++)
	{
		int num = rand() % 100;
		cout << num << " ";
		Array.push_back(num);
	}
	cout << endl;

	result = majority2(Array);
	cout << result << endl;
	
	
}