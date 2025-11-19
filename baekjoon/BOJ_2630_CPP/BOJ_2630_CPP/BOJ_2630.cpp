#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
int white = 0;
int blue = 0;

bool IsSameColor(int x, int y, int size)
{
    int color = arr[x][y];

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (arr[i][j] != color)
            {
                return false;
            }
        }
    }

    return true;
}

void Divide(int x, int y, int size)
{
    if (IsSameColor(x, y, size))
    {
        if (arr[x][y] == 0)
        {
            white++;
        }
        else
        {
            blue++;
        }
        return;
    }

    int half = size / 2;
    Divide(x, y, half);
    Divide(x, y + half, half);
    Divide(x + half, y, half);
    Divide(x + half, y + half, half);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    arr.assign(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    Divide(0, 0, N);

    cout << white << "\n" << blue;

    return 0;
}
