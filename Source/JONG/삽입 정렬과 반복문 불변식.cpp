#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// �ʱ�����, �������� �����ؼ� �����غ���.

//��������,
//���� �����̶�? ���ĵ� �迭�� ���ο� ���� �ش� �迭�� ���ĵ� ���� �� �� �ִ� ��ġ�� �����ϴ� ����.
void insertionSort(vector<int>& A) {
	int n = A.size();
	for (int i = 0; i < n; i++)
	{
		// �Һ��� a : A[0.... i - 1]������ �׻� ���ĵǾ��ִ�.
		// A[0 ... i -1] ���̿� A[i]�� �����ִ´�.
		int j = i;
		
		//A[j-1] > A[j]���,  �ݺ����� �����Ѵ�.
		while (j > 0 && A[j - 1] > A[j]) {
			// �Һ��� b : A[j+1... i] ������ ��� ���Ҵ� A[j]���� ũ��.
			//�Һ��� c : A[0...i]������ A[j]�� �����ϰ�� ���ĵǾ� �ִ�...

			swap(A[j - 1], A[j]);
			j--;
		}
	}
}

int main() {


}