#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// �ڿ����� ���μ� ���� ����� ���� ���� �迭 ��ȯ,
vector<int> factor(int n) {
	if (n == 1) return vector<int>(1, 1); // n = 1 �� ���� ����,
	vector<int> ret;
	for (int div = 2; n > 1; div++) {
		while (n % div == 0)
		{
			n /= div;
			ret.push_back(div);
		}
	}
	return ret;
}

int main()
{
	vector<int> result = factor(60);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

}