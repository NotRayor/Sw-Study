#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// A�� �������� ���ĵǾ� �ִ�. 
// ��� A[i-1] <= A[i] �� i ��ȯ����.
// �̶� A[-1] = �� ���Ѵ�, A[n]�� �� ���Ѵ��� ����
int binsearch(const vector<int>& A, int x)
{
	int n = A.size();
	// lo �ʱⰪ�� -1������, n=0�� ��쿡��, lo < hi�� �����Ѵ�. �׻� ����,
	int lo = -1, hi = n;
	//�ݺ��� �Һ��� 1 : lo < hi 
	// �Һ��� 2 : A[lo] < x <= A[hi]
	// �Һ����� ���⼭ �����ؾ��Ѵ�.

	// �ش� while ���ο� ���Դ�. lo�� hi�� 2�̻� ���̳���.  �׷���, lo,hi �� ���̿� mid���� ��ġ�Ѵ�.
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (A[mid] < x)
			lo = mid;
		else
			hi = mid;
		//���⼭�� �Һ����� �����ؾ���.
	}
	return hi;

}

int main()
{

}