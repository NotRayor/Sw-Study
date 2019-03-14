#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

// 다이어트 현황 파악
// M-이동평균이란? 최근 M개를 추출해서, 평균을 구하는 것이다.
vector<double> movingAverage(vector<double>& A, int M)
{
	int N = A.size();
	vector<double> movingAvg;
	for (int i = M - 1; i < N; i++)
	{
		double partialSum = 0;
		for (int j = 0; j < M; j++)
		{
			partialSum += A[i - j];
		}
		movingAvg.push_back(partialSum / M);
	}

	return movingAvg;
}

vector<double> movingAverage2(vector<double>& A, int M)
{
	int N = A.size();
	double partialSum = 0;
	vector<double> ret;

	// 0 ~ M-1 까지 더하고 M으로 나누면 시작의 M-이동평균
	// 0이 포함되서 M-1로..나눈다.
	// M으로 고려하는 이유는, 이동평균을 연산하기 위해서는 최소한 M개의 자료가 앞에 있어야하기 때문이다.

	// 0부터 M - 2까지 더한다.  
	for (int i = 0; i < M - 1 ; i++)
	{
		partialSum += A[i];
	}

	// 이제부터 이동평균의 맨 앞부분을 빼고, 1증가시킨 부분을 추가한다.
	for (int i = M - 1; i < N; ++i)
	{
		partialSum += A[i];
		ret.push_back(partialSum / M); 
		partialSum -= A[i - M + 1];
	}
	
	return ret;
}

int main()
{
	vector<double> weight;
	int M = 3;
	srand(time(NULL));

	for (int i = 0; i < 12; i++) {
		int num = rand() % 20 + 40;
		weight.push_back(num);
	}

	vector<double> avg = movingAverage2(weight, M);

	int N = avg.size();
	for (int i = 0; i < N; i++)
		cout << i + M  << ": " << avg[i] << endl;

}


/*
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
*/