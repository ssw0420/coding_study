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
	vector<int> stickHeight(N);

	for (int i = 0; i < N; i++)
	{
		cin >> stickHeight[i];
	}

	int longest = stickHeight[N - 1];
	int count = 1;
	for (int i = N - 2; i >= 0; i--)
	{
		if (longest < stickHeight[i])
		{
			longest = stickHeight[i];
			count++;
		}
	}

	cout << count;
	return 0;
}