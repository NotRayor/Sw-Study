#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// 초기조건, 유지조건 분할해서 생각해보자.

//삽입정렬,
//삽입 정렬이란? 정렬된 배열에 새로운 값을 해당 배열이 정렬된 값이 될 수 있는 위치에 삽입하는 정렬.
void insertionSort(vector<int>& A) {
	int n = A.size();
	for (int i = 0; i < n; i++)
	{
		// 불변식 a : A[0.... i - 1]까지는 항상 정렬되어있다.
		// A[0 ... i -1] 사이에 A[i]를 끼워넣는다.
		int j = i;
		
		//A[j-1] > A[j]라면,  반복문을 진행한다.
		while (j > 0 && A[j - 1] > A[j]) {
			// 불변식 b : A[j+1... i] 구간의 모든 원소는 A[j]보다 크다.
			//불변식 c : A[0...i]구간은 A[j]를 제외하고는 정렬되어 있다...

			swap(A[j - 1], A[j]);
			j--;
		}
	}
}

int main() {


}