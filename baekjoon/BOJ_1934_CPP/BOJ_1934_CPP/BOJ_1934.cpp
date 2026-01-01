#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	int A, B;
	int result = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;

		int tempA = A;
		int tempB = B;
		while (true)
		{
			if (tempA < tempB)
			{
				tempA += A;
			}
			else if (tempA > tempB)
			{
				tempB += B;
			}
			else if (tempA == tempB)
			{
				result = tempA;
				cout << result << '\n';
				break;
			}
		}
	}

	return 0;
}