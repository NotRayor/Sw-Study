#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;


// ���ڰ��� const�� ���̴� ������? ����ε�.. ���� �߰����� �������� �ǰ� >> ����
int majority(const vector<int>& A)
{
	int N = A.size();
	int majority = -1, majorityCount = 0;
	for (int i = 0; i < N; i++)
	{
		// A�� �����ϴ� A[i]�� ���� ����.
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
	// ���� �ִ� ���� ��
	return majority;
}

// ��� �߰���� ��������, 0~100���� �����ϱ�,
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