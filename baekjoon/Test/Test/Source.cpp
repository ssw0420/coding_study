#include <iostream>
#include <vector>

using namespace std;

int func1(int N)
{
	int total = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			total += i;
		}
	}
	return total;
}

int func2(int arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] + arr[j] == 100)
			{
				return 1;
			}
		}
	}
	return 0;
}

int func3(int N)
{
	for (int i = 1; i * i <= N; i++)
	{
		if (i * i == N)
		{
			return 1;
		}

		return 0;
	}
	
}

// N이하의 수 중에서 가장 큰 2의 거듭제곱 수를 반환
// ex) N = 5일때, 2^0, 2^1, 2^2가 있는데 2^2인 4가 젤 크니까 4를 반환
int func4(int N)
{
	int value = 1;
	while (2 * value <= N)
	{
		value *= 2;
	}
	return value;
}

// 512MB = 1.2억개의 int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	cout << func4(N);

	// func2
	//int* arr = new int[N];

	//for (int i = 0; i < N; i++)
	//{
	//	cin >> arr[i];
	//}

	//
	//cout << func2(arr, N);

	//delete[] arr;

	
	return 0;
}