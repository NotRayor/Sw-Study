#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS Breadth.. 큐가 사용된다. 
// DFS depth.. 깊이 우선 탐색, 스택이 사용된다.

// 1. 스택의 최상단 노드를 확인한다.
// 2. 최상단 노드에게 방문하지 않은 인접노드가 있으면 그 노드를 스택에 넣고
// 방문처리, 방문하지 않은 인접노드가 없으면  스택에서 최상단 노드를 뺍니다.

/*
int number = 7;
int c[8]; // 방문유무
vector<int> a[8]; // vector == stack? 스택, FIFO 피포

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

	cout << x << ' '; // dfs 요소 값 표현

	// a[x]의 모든 요소값을 방문, 
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
	
	scanf("%d", &N); // 노드의 개수 
	scanf("%d", &M); // 간선의 개수
	scanf("%d", &V); // 탐색을 시작할 번호

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
//1과 2를 연결
a[1].push_back(2);
a[2].push_back(1);

//1과 3을 연결
a[1].push_back(3);
a[3].push_back(1);

//2와 3을 연결
a[2].push_back(3);
a[3].push_back(2);

//2와 4을 연결
a[2].push_back(4);
a[4].push_back(2);

//2와 5을 연결
a[2].push_back(5);
a[5].push_back(2);

//3와 6을 연결
a[3].push_back(6);
a[6].push_back(3);

//3와 7을 연결
a[3].push_back(7);
a[7].push_back(3);

//4와 5을 연결
a[4].push_back(5);
a[5].push_back(4);

//6와 7을 연결
a[6].push_back(7);
a[7].push_back(6);

dfs(1);
*/