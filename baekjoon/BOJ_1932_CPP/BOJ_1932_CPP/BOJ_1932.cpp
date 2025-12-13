#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i].resize(i + 1);

		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> dp(n);
	for (int i = 0; i < n; i++)
	{
		dp[i].resize(i + 1);
	}

	dp[0][0] = arr[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) // left
			{
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			}
			else if (j == i) // right
			{
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			}
			else // middle
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
			}
		}
	}

	int answer = 0;

	for (int j = 0; j < n; j++)
	{
		answer = max(answer, dp[n - 1][j]);
	}

	cout << answer;

	return 0;
}