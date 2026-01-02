#include <iostream>

using namespace std;

long long Get_GCD(long long a, long long b)
{
	while (b != 0)
	{
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long A, B;
	cin >> A >> B;

	long long gcd = Get_GCD(A, B);
	long long result = (A / gcd) * B;

	cout << result;

	return 0;
}