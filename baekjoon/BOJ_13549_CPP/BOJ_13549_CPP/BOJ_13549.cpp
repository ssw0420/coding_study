#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int dist[MAX];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;

	cin >> N >> K;
	fill(dist, dist + MAX, -1); // First, Last, Fill Value

	deque<int> dq;

	dq.push_back(N);
	dist[N] = 0;

	while (!dq.empty())
	{
		int cur = dq.front();
		dq.pop_front();

		if (cur == K)
		{
			cout << dist[K] << "\n";
			return 0;
		}


		if (cur * 2 < MAX && (dist[cur * 2] == -1 || dist[cur * 2] > dist[cur]))
		{
			dist[cur * 2] = dist[cur];
			dq.push_front(cur * 2);
		}

		if (cur + 1 < MAX && (dist[cur + 1] == -1 || dist[cur + 1] > dist[cur] + 1))
		{
			dist[cur + 1] = dist[cur] + 1;
			dq.push_back(cur + 1);
		}

		if (cur - 1 >= 0 && (dist[cur - 1] == -1 || dist[cur - 1] > dist[cur] + 1))
		{
			dist[cur - 1] = dist[cur] + 1;
			dq.push_back(cur - 1);
		}
		
	}


	return 0;
}