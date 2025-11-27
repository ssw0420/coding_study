#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;

	cin >> N >> K;

	vector<int> A(N);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int count = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (A[i] > K) continue;

		count += K / A[i];
		K %= A[i];
	}

	cout << count;

	return 0;
}