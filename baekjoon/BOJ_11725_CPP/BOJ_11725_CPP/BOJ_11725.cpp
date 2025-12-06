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

	vector<vector<int>> graph(N + 1);
	vector<int> parent(N + 1, 0);

	for (int i = 0; i < N - 1; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}

	queue<int> q;
	q.push(1);
	parent[1] = -1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : graph[cur])
		{
			if (parent[next] == 0)
			{
				parent[next] = cur;
				q.push(next);
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}