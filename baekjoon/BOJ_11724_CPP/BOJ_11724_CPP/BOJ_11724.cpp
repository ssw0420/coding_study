#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;

    for (int next : graph[node])
    {
        if (!visited[next])
        {
            dfs(next);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    graph.assign(N + 1, vector<int>());
    visited.assign(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int result = 0;

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            result++;
        }
    }
    cout << result;

	return 0;
}