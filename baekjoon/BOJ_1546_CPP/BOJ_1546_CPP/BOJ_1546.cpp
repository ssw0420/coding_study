#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int max_score;
	float new_total_score = 0.f;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	max_score = *max_element(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		new_total_score += (float)v[i] / max_score * 100;
	}

	cout << new_total_score / N;

	return 0;
}