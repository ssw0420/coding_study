#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		vector<vector<int>> table(2, vector<int>(n));

		for (int row = 0; row < 2; row++)
		{
			for (int col = 0; col < n; col++)
			{
				cin >> table[row][col];
			}
		}

		if (n == 1)
		{
			cout << max(table[0][0], table[1][0]) << '\n';
			continue;
		}

		vector<vector<int>> dp(2, vector<int>(n));

		dp[0][0] = table[0][0];
		dp[1][0] = table[1][0];

		dp[0][1] = table[0][1] + dp[1][0];
		dp[1][1] = table[1][1] + dp[0][0];

		for (int i = 2; i < n; i++)
		{
			dp[0][i] = table[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = table[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}

	return 0;
}