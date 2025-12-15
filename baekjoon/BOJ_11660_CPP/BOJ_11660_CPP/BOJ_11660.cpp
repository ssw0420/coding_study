#include <iostream>
#include <vector>


using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N >> M;

	vector<vector<int>> arr(N + 1, vector<int>(N + 1 , 0));
	vector<vector<int>> prefix(N + 1, vector<int>(N + 1, 0));

    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            cin >> arr[r][c];

            prefix[r][c] =    prefix[r - 1] [c]
                            + prefix[r]     [c - 1]
                            - prefix[r - 1] [c - 1]
                            + arr[r]        [c];
        }
    }

    int x1, y1, x2, y2;

    for (int i = 0; i < M; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        int result =      prefix[x2]        [y2]
                        - prefix[x1 - 1]    [y2]
                        - prefix[x2]        [y1 - 1]
                        + prefix[x1 - 1]    [y1 - 1];

        cout << result << '\n';
    }

	return 0;
}