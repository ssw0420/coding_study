#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	queue<int> people;
	for (int i = 1; i < N + 1; i++)
	{
		people.push(i);
	}

	int K;
	cin >> K;
	cout << '<';

	int count = 0;
	int num = 0;
	while (!people.empty())
	{
		count++;
		num = people.front();
		people.pop();
		if (count != K)
		{
			people.push(num);
		}
		else if (count == K)
		{
			cout << num;
			if (!people.empty())
			{
				cout << ", ";
			}
			count = 0;
		}
	}

	cout << '>';

	return 0;
}