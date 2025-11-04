#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	dp[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;  // 항상 가능한 기본 연산 : 1빼기
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}	
	}

	cout << dp[N];

	return 0;
}