#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long N;

	cin >> N;
	vector<long> arr(N);

	for (long i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	ostringstream out;
	for (int i = 0; i < N; i++)
		out << arr[i] << '\n';
	cout << out.str();

	return 0;
}