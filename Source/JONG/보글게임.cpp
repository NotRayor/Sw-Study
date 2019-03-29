#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

char board[5][5] = {
	'A','A','A','A','A',
	'A','A','A','A','A',
	'A','A','A','A','B',
	'A','A','A','A','A',
	'A','A','A','A','A'
};

// 주위 8칸의 방향
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
bool inRange(int x, int y) {
	if (x < 0 || y < 0 || x > 4 || y > 4) 
		return false;
	else 
		return true;
}

// 5x5 보글 게임 판의 해당 위치에서 주어진 단어가 시작하는지를 반환,
bool hasWord(int x, int y, const string& word) {
	//기저사례1. 시작 위치가 범위 밖이면 실패,
	if (!inRange(x, y)) return false;
	//기저사례2. 첫 글자가 일치하지 않으면 실패,
	if (board[x][y] != word[0]) return false;
	//기저사례3. 단어 길이가 1이면 성공
	if (word.size() == 1) return true;
	//인접한 여덞칸 확인,
	for (int direction = 0; direction < 8; ++direction) {
		int nextX = x + dx[direction];
		int nextY = y + dy[direction];
		// 다음 칸이 범위 안에 있는지 첫글자는 일치하는지 확인할 필요 없다. 기저사례를 이용해 처리했기 때문이다.
		if (hasWord(nextX, nextY, word.substr(1)))
			return true;
	}
	return false;
}


int main() {
	
	cout << hasWord(3, 3, "BAAAAAAA") << endl;

}