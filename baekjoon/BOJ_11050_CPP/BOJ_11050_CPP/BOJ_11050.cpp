#include <iostream>

using namespace std;

long long factorial(long long num);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long K, N;

	cin >> N >> K;

	cout << factorial(N) / (factorial(K) * factorial(N - K));

	return 0;
}

long long factorial(long long num)
{
	long long result = 1;
	for (long long i = 2; i <= num; i++)
	{
		result *= i;
	}
	return result;
}