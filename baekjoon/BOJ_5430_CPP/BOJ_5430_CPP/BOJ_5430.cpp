#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string p;
		string arr;
		int n;

		cin >> p >> n >> arr;

		deque<int> dq;

		int num = 0;
		bool isNumber = false;

		for (char c : arr)
		{
			if (isdigit(c))
			{
				num = num * 10 + (c - '0');
				isNumber = true;
			}
			else
			{
				if (isNumber)
				{
					dq.push_back(num); // 완성된 숫자 삽입
					num = 0;
					isNumber = false;
				}
			}
		}

		bool isReversed = false;
		bool isError = false;

		for (char command : p)
		{
			if (command == 'R') // R
			{
				isReversed = !isReversed;
			}
			else // D
			{
				if (dq.empty())
				{
					isError = true;
					break;
				}

				if (!isReversed)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
			}
		}

		if (isError)
		{
			cout << "error\n";
			continue;
		}

		cout << "[";

		if (!isReversed)
		{
			for (int i = 0; i < dq.size(); i++)
			{
				cout << dq[i];
				if (i + 1 < dq.size())
				{
					cout << ",";
				}
			}
		}
		else
		{
			for (int i = dq.size() - 1; i >= 0; i--)
			{
				cout << dq[i];
				if (i > 0)
				{
					cout << ",";
				}
			}
		}

		cout << "]\n";
	}

	return 0;
}