#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> selected;

void dfs(int startNum)
{
	if (selected.size() == M)
	{
		for (int num : selected)
		{
			cout << num << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = startNum; i <= N; i++)
	{
		selected.push_back(i);
		dfs(i + 1); // next number
		selected.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	dfs(1);

	return 0;
}