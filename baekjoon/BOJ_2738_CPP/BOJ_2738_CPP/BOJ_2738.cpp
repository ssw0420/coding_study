#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> vecA(N, vector<int>(M));
	vector<vector<int>> vecB(N, vector<int>(M));
	vector<vector<int>> vecR(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> vecA[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> vecB[i][j];
			vecR[i][j] = vecA[i][j] + vecB[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << vecR[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}