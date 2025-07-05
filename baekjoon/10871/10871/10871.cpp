#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	vector<int> A;
	int X;
	int num = 0;

	cin >> N >> X;
	A.reserve(N); // �޸𸮸� �̸� �Ҵ� (ũ�� ��ü�� Ŀ���鼭 0���� �Ҵ�Ǵ� ���� �ƴ�, ���̶�� ���� ����)
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num < X)
		{
			A.push_back(num);
		}
	}

	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}

	// range-based for loop - c++ 11���� ����
	/*for (int value : A)
	{
		cout << value << " ";
	}*/

	return 0;
}


//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int N, X, num;
//	cin >> N >> X;
//
//	for (int i = 0; i < N; ++i) {
//		cin >> num;
//		if (num < X) {
//			cout << num << " ";
//		}
//	}
//
//	return 0;
//}