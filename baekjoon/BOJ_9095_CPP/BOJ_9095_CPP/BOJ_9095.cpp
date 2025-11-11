#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	vector<int> n(T);
	for (int i = 0; i < T; i++)
	{
		cin >> n[i];
	}

	for (int i = 0; i < T; i++)
	{
		int num = n[i];

		vector<int> dp(num + 1, 0); // 각 수를 만드는 경우의 수 저장용 배열

		// 기본 경우 (초기값)
		dp[1] = 1; // 1 = (1)
		if (num >= 2)
			dp[2] = 2; // 2 = (1+1), (2)
		if (num >= 3)
			dp[3] = 4; // 3 = (1+1+1), (1+2), (2+1), (3)

		// 점화식 적용
		for (int j = 4; j <= num; j++)
		{
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}

		cout << dp[num] << '\n';
	}

	return 0;
}