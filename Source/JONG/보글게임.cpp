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

// ���� 8ĭ�� ����
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
bool inRange(int x, int y) {
	if (x < 0 || y < 0 || x > 4 || y > 4) 
		return false;
	else 
		return true;
}

// 5x5 ���� ���� ���� �ش� ��ġ���� �־��� �ܾ �����ϴ����� ��ȯ,
bool hasWord(int x, int y, const string& word) {
	//�������1. ���� ��ġ�� ���� ���̸� ����,
	if (!inRange(x, y)) return false;
	//�������2. ù ���ڰ� ��ġ���� ������ ����,
	if (board[x][y] != word[0]) return false;
	//�������3. �ܾ� ���̰� 1�̸� ����
	if (word.size() == 1) return true;
	//������ ����ĭ Ȯ��,
	for (int direction = 0; direction < 8; ++direction) {
		int nextX = x + dx[direction];
		int nextY = y + dy[direction];
		// ���� ĭ�� ���� �ȿ� �ִ��� ù���ڴ� ��ġ�ϴ��� Ȯ���� �ʿ� ����. ������ʸ� �̿��� ó���߱� �����̴�.
		if (hasWord(nextX, nextY, word.substr(1)))
			return true;
	}
	return false;
}


int main() {
	
	cout << hasWord(3, 3, "BAAAAAAA") << endl;

}