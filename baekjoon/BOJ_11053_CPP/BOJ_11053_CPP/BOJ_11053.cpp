#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A;

	cin >> A;
	vector<int> arr(A);

	for (int i = 0; i < A; i++)
	{
		cin >> arr[i];
	}

	vector<int> dp(A, 1);

	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int result = *max_element(dp.begin(), dp.end());

	cout << result;

	return 0;
}