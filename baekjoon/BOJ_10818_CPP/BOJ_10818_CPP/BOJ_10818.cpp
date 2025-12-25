#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int min_val = 1000001;
	int max_val = -1000001;

	for (int i = 0; i < N; i++)
	{
		int cur;
		cin >> cur;

		if (cur < min_val) min_val = cur;
		
		if (cur > max_val) max_val = cur;
	}

	cout << min_val << " " << max_val;

	return 0;
}