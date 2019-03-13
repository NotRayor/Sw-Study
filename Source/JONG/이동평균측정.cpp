#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

// 실수 배열 A 존재 시, 각 위치에서의 M-이동 평균 값을 구해라.
vector<double> movingAverage(const vector<double>& A, int M)
{
	vector<double> ret;
	int N = A.size();

	for (int i = M - 1; i < N; i++) {
		double partialSum = 0;
		for (int j = 0; j < M; j++) {
			partialSum += A[i - j];
		}
		ret.push_back(partialSum / M);
	}

	return ret;
}

int main()
{
	vector<double> weight;
	vector<double> ret;
	int M = 3;
	srand(time(NULL));

	for (int i = 0; i < 12; i++)
	{
		int num = rand() % 20 + 40;
		weight.push_back(num);
	}

	ret = movingAverage(weight, M);

	for (int i = 0; i < weight.size() - M + 1; i++)
	{
		cout << ret[i] << endl;
	}
}