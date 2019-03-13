#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

// �Ǽ� �迭 A ���� ��, �� ��ġ������ M-�̵� ��� ���� ���ض�.
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