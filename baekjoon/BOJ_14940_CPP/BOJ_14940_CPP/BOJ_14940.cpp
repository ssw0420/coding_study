#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;

	cin >> n >> m;
	vector<vector<int>> maps(n, vector<int>(m));
	vector<vector<int>> dist(n, vector<int>(m, -1)); // 원래는 갈 수 있지만, 결과부분에서 못가는 경우 -1을 출력해야 하기 때문

	int sx = -1, sy = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 2)
			{
				sx = i;
				sy = j;
			}
		}
	}

	// BFS
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	queue<pair<int, int>> q; // x, y
	q.push({ sx, sy });
	dist[sx][sy] = 0;


	while (!q.empty())
	{
		int x = q.front().first; // x
		int y = q.front().second; // y
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) continue;
			if (maps[nextX][nextY] == 0) continue;
			if (dist[nextX][nextY] != -1) continue; // 이미 방문함

			dist[nextX][nextY] = dist[x][y] + 1; // 거리 =  현재 거리 + 1
			q.push({ nextX, nextY });
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maps[i][j] == 0)
			{
				cout << 0 << " ";
			}
			else if (dist[i][j] == -1)
			{
				cout << -1 << " ";
			}
			else
			{
				cout << dist[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}