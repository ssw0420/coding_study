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

void InputArray()
{

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

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