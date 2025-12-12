#include <iostream>

using namespace std;

long long modPow(long long A, long long B, long long C)
{
	long long result = 1;
	A %= C;

	while (B > 0)
	{
		if (B & 1)
		{
			result = (result * A) % C;
		}

		A = (A * A) % C;

		B >>= 1;
	}

	return result;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long A, B, C;
	cin >> A >> B >> C;

	cout << modPow(A, B, C);

	return 0;
}