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
	A.reserve(N); // 메모리만 미리 할당 (크기 자체가 커지면서 0으로 할당되는 것이 아님, 값이라는 것은 없음)
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

	// range-based for loop - c++ 11부터 도입
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