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

// N������ �� �߿��� ���� ū 2�� �ŵ����� ���� ��ȯ
// ex) N = 5�϶�, 2^0, 2^1, 2^2�� �ִµ� 2^2�� 4�� �� ũ�ϱ� 4�� ��ȯ
int func4(int N)
{
	int value = 1;
	while (2 * value <= N)
	{
		value *= 2;
	}
	return value;
}

// 512MB = 1.2�ﰳ�� int
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