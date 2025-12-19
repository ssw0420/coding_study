#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
	int N;
	int K;
	int W;

	cin >> N >> K;

	vector<pair<int, int>> items(N, make_pair(0, 0));


	for (int i = 0; i < N; i++)
	{
		cin >> items[i].first >> items[i].second;
	}

	vector<int> dp(K + 1, 0);

	for (int i = 0; i < N; i++)
	{
		int weight = items[i].first;
		int value = items[i].second;

		for (int w = K; w >= weight; w--)
		{
			dp[w] = max(dp[w], dp[w - weight] + value);
		}
	}

	cout << dp[K];

	return 0;
}