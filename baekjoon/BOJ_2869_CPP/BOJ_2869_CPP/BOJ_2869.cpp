#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, V;
	cin >> A >> B >> V;

	int day = (V - A) / (A - B); // ������ �� ������

	if ((V - A) % (A - B) != 0) // �� �� ��� �Ϸ� ����
	{
		day++;
	}

	cout << day + 1; // ������ ���� �̸� �������Ƿ� �Ϸ� ����

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