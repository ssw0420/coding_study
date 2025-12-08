#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> selected;

void dfs(int start, int depth)
{
	if (depth == M)
	{
		for (int x : selected)
		{
			cout << x << " ";
		}
		cout << "\n";
		return;
	}

	int prev = -1;

	for (int i = start; i < N; i++)
	{
		if (prev == arr[i]) continue;

		selected.push_back(arr[i]);
		dfs(i, depth + 1);
		selected.pop_back();

		prev = arr[i];
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	arr.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	dfs(0, 0);

	return 0;
}