#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N;
	cin >> N;

	long long TshirtOrders[6];
	for (int i = 0; i < 6; i++)
	{
		cin >> TshirtOrders[i];
	}

	long long T, P;
	cin >> T >> P;

	long long TshirtBundles = 0;
	for (int i = 0; i < 6; i++)
	{
		TshirtBundles += (TshirtOrders[i] + T - 1) / T;
	}

	long long PenBundles = N / P;  
	long long SinglePens = N % P;

	cout << TshirtBundles << "\n";
	cout << PenBundles << " " << SinglePens << "\n";

	return 0;
}