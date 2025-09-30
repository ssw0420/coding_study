#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;

	cin >> N;
	vector<string> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end()); // ���� ���� ����

	// unique�� ���� ������ �ߺ� ���Ҹ� ���� �ڷ� ���� �׷��Ƿ� ������ ���� �Ǿ�� ��
	// unique�� �ϸ� �ߺ� ���ۺκ��� ����Ŵ (�� �� erase�� �ش� �κк��� ���� �ڸ���)
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	
	// ���ڿ� ���̴� ���� ������ �� �� ������ unsignedŸ�� size_t ��� ����������, int �Ǵ� long long�� ä���� ����

	sort(vec.begin(), vec.end(),	[](const string& a, const string& b)
	{
		if (a.size() == b.size()) return a < b;
		return a.size() < b.size();
	});

	for (int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i] << "\n";
	}

	return 0;
}


//auto f1 = [](int a, int b) { return a + b; };       // �ڵ� �߷� �� int
//auto f2 = [](double a, double b) { return a + b; }; // �ڵ� �߷� �� double
//auto f3 = [](bool x) -> double {                    // ����� ��ȯ
//	if (x) return 1;
//	else return 1.5;
//	};
//
//cout << f1(2, 3) << "\n";    // 5
//cout << f2(2.5, 3.5) << "\n"; // 6.0
//cout << f3(true) << "\n";    // 1.0