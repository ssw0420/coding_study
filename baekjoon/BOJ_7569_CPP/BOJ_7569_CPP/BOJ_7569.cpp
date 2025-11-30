#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int dz[6] = { 1, -1, 0, 0, 0, 0 };
	int dx[6] = { 0, 0, -1, 1, 0, 0 };
	int dy[6] = { 0, 0, 0, 0, -1, 1 };

	int M, N, H;
	cin >> M >> N >> H;

	vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));

	int result = 0;

	for (int h = 0; h < H; h++)
	{
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				cin >> box[h][n][m];
			}
		}
	}

	queue<tuple<int, int, int>> q;

	// 이미 익은 토마토를 큐에 삽입
	for (int h = 0; h < H; h++)
	{
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				if (box[h][n][m] == 1)
				{
					q.push({ h, n, m });
				}
			}
		}
	}


	// BFS
	while (!q.empty())
	{
		tuple<int, int, int> cur = q.front();
		int h = get<0>(cur);
		int n = get<1>(cur);
		int m = get<2>(cur);
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nextH = h + dz[i];
			int nextN = n + dx[i];
			int nextM = m + dy[i];

			if (nextH < 0 || nextH >= H ||
				nextN < 0 || nextN >= N ||
				nextM < 0 || nextM >= M) continue;

			if (box[nextH][nextN][nextM] != 0) continue;

			box[nextH][nextN][nextM] = box[h][n][m] + 1;
			q.push({ nextH, nextN, nextM });
		}
	}

	for (int h = 0; h < H; h++)
	{
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				if (box[h][n][m] == 0)
				{
					cout << -1;
					return 0;
				}

				result = max(result, box[h][n][m]);
			}
		}
	}

	cout << result - 1; // 초기값이 1이므로, 실제 날짜는 1을 빼야 함

	return 0;
}