#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int V, E;
	cin >> V >> E;

	int K;
	cin >> K; // Start Point

	//graph.assign(V + 1, vector<int>(V + 1, -1));
	vector<vector<pair<int, int>>> graph;
	graph.assign(V + 1, vector<pair<int, int>>());

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w }); // u -> v, w: weight
	}

    vector<int> dist(V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[K] = 0;
    pq.push({ 0, K });

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dist[cur]) continue;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int weight = graph[cur][i].second;

            if (dist[next] > dist[cur] + weight)
            {
                dist[next] = dist[cur] + weight;
                pq.push({ dist[next], next });
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << dist[i] << '\n';
        }
    }

	// graph[1] = { -1, -1, 2, 3, 0, 0 }
	// graph[2] = { -1, -1, -1, 4, 5, -1 }
	// graph[3] = { -1, -1, -1, -1, 6, -1 }
	// graph[4] = { -1, -1, -1, -1, -1, -1 }
	// graph[5] = { -1, 1, -1, -1, -1, -1 }

	// ex)
	// graph [1] = { -1, -1, 2, 3, 0, 0 }
	// graph [1][2] = 2;
	// graph [1][3] = 3;

	return 0;
}