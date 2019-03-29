#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec;


// 1���� n������ ���� ����ϴ� �ݺ� �Լ��� ��� �Լ�
// �ʼ����� n >= 1
int sum(int n) {
	if (n == 1) return 1; // �������,

	return n + (sum(n - 1));
}

void printPicked(vector<int>& v, int toPick) {
	for (int i = 0; i < v.size(); i++)
	{
		if ((i + 1)% toPick == 0)
			cout << v[i] << endl;
		else
			cout << v[i];
	}
}
// ��ø �ݺ��� ��ü�ϱ�,
// n : ��ü ������ ��
// picked : ���ݱ��� �� ���ҵ��� ��ȣ
// toPick : �� �� ������ ��
void pick(int n, vector<int>& picked, int toPick) {
	// �������, �� �� ���Ұ� ����.
	if (toPick == 0) {
		printPicked(picked, 3);
		return; 
	}
	// �� �� �ִ� ���� ���� ��ȣ ���,
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	// �� �ܰ迡�� ���� �ϳ��� ����.
	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back(); // ����Ʈ ���Ŀ�, �ش� ��ɾ��, ����� ���ο� ���� �߰��ϸ� �ݺ��Ѵ�
	}

	return;
}


int main() {

	cout << sum(3) << endl;
	pick(5, vec, 3);

}