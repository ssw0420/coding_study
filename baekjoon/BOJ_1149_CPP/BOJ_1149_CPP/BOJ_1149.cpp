#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> house(N, vector<int>(3));
	vector<vector<int>> dp(N, vector<int>(3));

	for (int i = 0; i < N; i++)
	{
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}

	dp[0][0] = house[0][0]; // R
	dp[0][1] = house[0][1]; // G
	dp[0][2] = house[0][2]; // B

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = house[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = house[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = house[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << min({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });

	return 0;
}