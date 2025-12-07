#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> selected;
vector<bool> visited;

void dfs(int depth)
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

	for (int i = 0; i < N; i++)
	{
		if (visited[i]) continue;
		if (prev == arr[i]) continue;

		visited[i] = true;
		selected.push_back(arr[i]);

		dfs(depth + 1);

		visited[i] = false;
		selected.pop_back();

		prev = arr[i];
	}
	
}

int main(void)
{
	cin >> N >> M;
	arr.resize(N);
	visited.assign(N, false);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	dfs(0);

	return 0;
}