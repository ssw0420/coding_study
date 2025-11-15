#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int y, int x,
    vector<vector<int>>& board,
    vector<vector<bool>>& visited,
    int N, int M)
{
    visited[y][x] = true;

    for (int d = 0; d < 4; d++)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];

        // in range
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

        if (board[ny][nx] == 1 && !visited[ny][nx])
        {
            dfs(ny, nx, board, visited, N, M);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int M, N, K;
        cin >> M >> N >> K;

        vector<vector<int>> board(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        int worms = 0;

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (board[y][x] == 1 && !visited[y][x])
                {
                    dfs(y, x, board, visited, N, M);
                    worms++;
                }
            }
        }

        cout << worms << "\n";
    }

    return 0;
}