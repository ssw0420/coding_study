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

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	vector<int> sortedArr = arr;

	sort(sortedArr.begin(), sortedArr.end());
	sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

	for (int i = 0; i < N; i++)
	{
		int result = lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]) - sortedArr.begin();
		cout << result << " ";
	}

	return 0;
}