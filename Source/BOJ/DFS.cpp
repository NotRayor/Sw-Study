#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


//dfs에 들어오면 '방문'으로 판단,
// 해당 위치에 check true로 해준다.
void dfs(int start, vector<int> graph[], bool check[])
{
	check[start] = true;
	printf("%d", start);

	// 각 그래프 사이즈 만큼 반복
	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i];
		//방문 X면?
		if (check[next] == false)
		{
			// 재귀함수 호출,
			dfs(next, graph, check);
		}
	}
}

int main()
{
	int n, m, start;
	cin >> n >> m >> start;

	vector<int> *graph = (vector<int>*)malloc(sizeof(vector<int>) * (n+1));
	bool *check = (bool*)malloc(sizeof(bool) * (n + 1));
	
	fill(check, check + n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//Sorting은 왜??
	// 나중에 하나의 정점에서 다음을 탐색할 때 node값에 순차적으로 접근해야하기 때문
	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	//dfs
	dfs(start, graph, check);
	printf("\n");

	return 0;
}