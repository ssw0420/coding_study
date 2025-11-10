#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int linkCount;
    cin >> linkCount;

    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < linkCount; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    int infectedCount = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                infectedCount++;
            }
        }
    }

    cout << infectedCount;
    return 0;
}
