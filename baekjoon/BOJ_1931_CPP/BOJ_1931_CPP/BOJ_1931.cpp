#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), compare);

	int count = 0;
	int last = 0;

	for (int i = 0; i < N; i++)
	{
		if (v[i].first >= last)
		{
			count++;
			last = v[i].second;
		}
	}

	cout << count;

	return 0;
}