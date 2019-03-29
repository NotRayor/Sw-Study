#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MIN = numeric_limits<int>::min();

// for문 3개를 돌리니.. 단순하게만 봐도 O(N^3)
int inefficientMaxSum(const vector<int>& A)
{
	int N = A.size(), ret = MIN;
	int m = MIN;
	//int min = MIN;

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			int sum = 0;
			for (int z = i; z <= j; z++)
			{
				sum += A[z];
			}
			m = max(m, sum);
		}
	}

	return m;
}

// 이동평균때 썼던 방법을 적용.
// 연속된 부분 구간의 최대 합을 구한다. 시간복잡도 O(n^2)
int betterMaxSum(const vector<int>& A)
{
	int N = A.size(), ret = MIN;
	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = i; j < N; j++)
		{
			sum += A[j];
			ret = max(ret, sum);
		}
	}
	return ret;
}

// A[lo .. hi]의 연속된 부분 구간 최대 합을 구한다. O(nlogn)
// 분할정복알고리즘 - 퀵정렬
int fastMaxSum(const vector<int>& A, int lo, int hi)
{
	//기저 사례? : 구간 길이가 1,
	if (lo == hi) return A[lo];
	//배열을 A[lo.. mid], A[mid+1 .. hi] 두 조각으로 나눈다.
	int mid = (lo + hi) / 2;
	// 두 부분에 걸쳐있는 최대 합을 찾는다.  이 구간은
	//  A[i.. mid]와 A[mid + 1 .. j]형태를 갖는 구간의 합으로 이뤄짐
	// A[i .. mid] 형태를 갖는 최대 구간을 찾는다.
	int left = MIN, right = MIN, sum = 0;
	for (int i = mid; i >= lo; --i) {
		sum += A[i];
		left = max(left, sum);
	}
	//A[mid+1 .. j]형태를 갖는 최대 구간을 찾는다.
	sum = 0;
	for (int i = mid + 1; i <= hi; i++) {
		sum += A[i];
		right = max(right, sum);
	}
	//최대 구간이 두 조각 중 하나에만 속해 있는 경우, 답을 재귀 호출로 찾는다.
	int single = max(fastMaxSum(A, lo, mid),
		fastMaxSum(A, mid + 1, hi));

	//두 경우 중 최대치를 반환한다.
	return max(left + right, single);

}

//동적계획법, O(N)
//A[]의 연속된 부분 구간의 최대 합을 구한다. 시간 복잡도 : O(n)
int fastestMaxSum(const vector<int>& A){
	int N = A.size(), ret = MIN, psum = 0;
	for (int i = 0; i < N; i++)
	{
		psum = max(psum, 0) + A[i];
		ret = max(psum, ret);
	}
	return ret;
}

int main()
{
	vector<int> A;

	A.push_back(5);
	A.push_back(2);
	A.push_back(-8);
	A.push_back(7);
	A.push_back(1);
	A.push_back(9);


	cout << inefficientMaxSum(A) << endl;
	cout << betterMaxSum(A) << endl;
	cout << fastMaxSum(A, 0, 5) << endl;
	cout << fastestMaxSum(A) << endl;
}