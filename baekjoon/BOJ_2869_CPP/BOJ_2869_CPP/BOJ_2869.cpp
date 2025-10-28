#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, V;
	cin >> A >> B >> V;

	int day = (V - A) / (A - B); // 마지막 날 전까지

	if ((V - A) % (A - B) != 0) // 덜 찬 경우 하루 더함
	{
		day++;
	}

	cout << day + 1; // 마지막 날을 미리 빼놨으므로 하루 더함

	//int day = 0;
	//int height = 0;
	//while (height < V)
	//{
	//	height += A;

	//	day++;
	//	if (height >= V)
	//	{
	//		break;
	//	}
	//	height -= B;
	//}
	//cout << day;

	return 0;
}