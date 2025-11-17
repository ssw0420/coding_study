#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node)
{
	visited[node] = true;
	cout << node << ' ';

	for (int next : graph[node])
	{
		if (!visited[next]) 
		{
			dfs(next);
		}
	}
}

void bfs(int start)
{
	queue<int> q;
	visited.assign(N + 1, false);

	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		cout << cur << ' ';

		for (int next : graph[cur])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> V;

	graph.assign(N + 1, vector<int>());
	visited.assign(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	
	dfs(V);
	cout << '\n';
	visited.assign(N + 1, false);
	bfs(V);

	return 0;
}