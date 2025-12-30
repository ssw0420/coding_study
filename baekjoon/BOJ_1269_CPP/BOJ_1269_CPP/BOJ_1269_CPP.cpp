#include <iostream>
#include <unordered_set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B;

	cin >> A >> B;

	unordered_set<int> setA(A);
	unordered_set<int> setB(B);

	int temp;
	for (int i = 0; i < A; i++)
	{
		cin >> temp;
		setA.insert(temp);
	}

	for (int i = 0; i < B; i++)
	{
		cin >> temp;
		setB.insert(temp);
	}

	int count = 0;


	for (const auto& num : setA)
	{
		if (setB.find(num) == setB.end())
		{
			count++;
		}
	}

	for (const auto& num : setB)
	{
		if (setA.find(num) == setA.end())
		{
			count++;
		}
	}

	cout << count;

	return 0;
}