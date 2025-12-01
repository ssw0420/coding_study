#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, N;
	cin >> M >> N;

	vector<vector<int>> box(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> box[i][j];
		}
	}

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 1)
			{
				q.push({ i, j });
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		int x = cur.first;
		int y = cur.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N ||
				ny < 0 || ny >= M)
				continue;

			// 익을 수 없는 칸(-1) 또는 이미 익음(1 이상)
			if (box[nx][ny] != 0)
				continue;

			// 현재 날짜 + 1
			box[nx][ny] = box[x][y] + 1;

			q.push({ nx, ny });
		}
	}

	int result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// 익지 못한 토마토가 있을 경우
			if (box[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

			result = max(result, box[i][j]);
		}
	}

	// 최대값 - 1
	cout << result - 1;

	return 0;
}