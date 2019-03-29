#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec;


// 1부터 n까지의 합을 계산하는 반복 함수와 재귀 함수
// 필수조건 n >= 1
int sum(int n) {
	if (n == 1) return 1; // 기저사례,

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
// 중첩 반복문 대체하기,
// n : 전체 원소의 수
// picked : 지금까지 고른 원소들의 번호
// toPick : 더 고를 원소의 수
void pick(int n, vector<int>& picked, int toPick) {
	// 기저사례, 더 고를 원소가 없다.
	if (toPick == 0) {
		printPicked(picked, 3);
		return; 
	}
	// 고를 수 있는 가장 작은 번호 계산,
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	// 이 단계에서 원소 하나를 고른다.
	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back(); // 프린트 이후에, 해당 명령어로, 지우고 새로운 수를 추가하며 반복한다
	}

	return;
}


int main() {

	cout << sum(3) << endl;
	pick(5, vec, 3);

}