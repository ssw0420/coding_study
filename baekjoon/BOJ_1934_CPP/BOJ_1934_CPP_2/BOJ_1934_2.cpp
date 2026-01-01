#include <iostream>

using namespace std;

int GetGCD(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	int A, B;
	long long result = 0;

	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;

		int gcd = GetGCD(A, B);

		result = (long long)A * B / gcd; // A와 B의 곱이 int 범위를 벗어날 수 있으니 long long 사용

		cout << result << '\n';
	}

	return 0;
}