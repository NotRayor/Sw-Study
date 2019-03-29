#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// A는 오름차순 정렬되어 있다. 
// 결과 A[i-1] <= A[i] 인 i 반환하자.
// 이때 A[-1] = 음 무한대, A[n]을 양 무한대라고 하자
int binsearch(const vector<int>& A, int x)
{
	int n = A.size();
	// lo 초기값이 -1임으로, n=0인 경우에도, lo < hi를 만족한다. 항상 성립,
	int lo = -1, hi = n;
	//반복문 불변식 1 : lo < hi 
	// 불변식 2 : A[lo] < x <= A[hi]
	// 불변식은 여기서 성립해야한다.

	// 해당 while 내부에 들어왔다. lo와 hi가 2이상 차이난다.  그래서, lo,hi 값 사이에 mid값이 위치한다.
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (A[mid] < x)
			lo = mid;
		else
			hi = mid;
		//여기서도 불변식이 성립해야함.
	}
	return hi;

}

int main()
{

}