#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		string s;
		cin >> s;
		if (s == "0") break;

		int n = s.size();
		int arr[100001];

		bool result = true;
		for (int i = 0; i < n; i++)
		{
			arr[i] = s[i] - '0';
		}

		int k = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (i == k) break;

			if (arr[i] != arr[k])
			{
				result = false;
			}
			k++;
		}
		if (result)
		{
			cout << "yes\n";
		}
		else if (!result)
		{
			cout << "no\n";
		}
	}

	return 0;
}