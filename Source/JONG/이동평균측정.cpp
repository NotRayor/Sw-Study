#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

// ���̾�Ʈ ��Ȳ �ľ�
// M-�̵�����̶�? �ֱ� M���� �����ؼ�, ����� ���ϴ� ���̴�.
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

	// 0 ~ M-1 ���� ���ϰ� M���� ������ ������ M-�̵����
	// 0�� ���ԵǼ� M-1��..������.
	// M���� ����ϴ� ������, �̵������ �����ϱ� ���ؼ��� �ּ��� M���� �ڷᰡ �տ� �־���ϱ� �����̴�.

	// 0���� M - 2���� ���Ѵ�.  
	for (int i = 0; i < M - 1 ; i++)
	{
		partialSum += A[i];
	}

	// �������� �̵������ �� �պκ��� ����, 1������Ų �κ��� �߰��Ѵ�.
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
*/