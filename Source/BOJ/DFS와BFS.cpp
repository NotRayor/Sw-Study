#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS Breadth.. ť�� ���ȴ�. 
// DFS depth.. ���� �켱 Ž��, ������ ���ȴ�.

// 1. ������ �ֻ�� ��带 Ȯ���Ѵ�.
// 2. �ֻ�� ��忡�� �湮���� ���� ������尡 ������ �� ��带 ���ÿ� �ְ�
// �湮ó��, �湮���� ���� ������尡 ������  ���ÿ��� �ֻ�� ��带 ���ϴ�.

/*
int number = 7;
int c[8]; // �湮����
vector<int> a[8]; // vector == stack? ����, FIFO ����

void dfs(int x) {
	if (c[x]) return;
	c[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		dfs(y);
	}
}
*/

int c[1001];
int c2[1001];
vector<int> a[1001]; 

void dfs(int x)
{
	if (c[x]) return;
	c[x] = true;

	cout << x << ' '; // dfs ��� �� ǥ��

	// a[x]�� ��� ��Ұ��� �湮, 
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		dfs(y);
	}

}

void tree(int x, int y)
{
	a[x].push_back(y);
	a[y].push_back(x);
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	c2[start] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if (!c2[y]) {
				q.push(y);
				c2[y] = true;
			}
		}
	}
}

int main()
{
	int N, M, V;
	int x, y;
	
	scanf("%d", &N); // ����� ���� 
	scanf("%d", &M); // ������ ����
	scanf("%d", &V); // Ž���� ������ ��ȣ

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		tree(x, y);
	}

	dfs(V);
	printf("\n");
	bfs(V);



	return 0;
}



/*
//1�� 2�� ����
a[1].push_back(2);
a[2].push_back(1);

//1�� 3�� ����
a[1].push_back(3);
a[3].push_back(1);

//2�� 3�� ����
a[2].push_back(3);
a[3].push_back(2);

//2�� 4�� ����
a[2].push_back(4);
a[4].push_back(2);

//2�� 5�� ����
a[2].push_back(5);
a[5].push_back(2);

//3�� 6�� ����
a[3].push_back(6);
a[6].push_back(3);

//3�� 7�� ����
a[3].push_back(7);
a[7].push_back(3);

//4�� 5�� ����
a[4].push_back(5);
a[5].push_back(4);

//6�� 7�� ����
a[6].push_back(7);
a[7].push_back(6);

dfs(1);
*/