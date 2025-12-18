#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	string str;

	cin >> N;
	cin >> str;

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum += str[i] - '0';
	}

	cout << sum;

	return 0;
}