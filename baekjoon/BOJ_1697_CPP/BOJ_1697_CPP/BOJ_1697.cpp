#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<int> dist(100001, -1);
	queue<int> q;

	dist[N] = 0; // start point
	q.push(N);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == K)
        {
            cout << dist[cur];
            return 0;
        }

        int nexts[3] = { cur - 1, cur + 1, cur * 2 };

        for (int nx : nexts)
        {
            if (nx < 0 || nx > 100000) continue;
            if (dist[nx] != -1) continue;

            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }

	return 0;
}