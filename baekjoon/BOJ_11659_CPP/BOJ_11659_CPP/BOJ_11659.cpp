#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> arr(N + 1, 0);
	vector<int> sum(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << sum[r] - sum[l - 1] << '\n';
	}

	return 0;
}