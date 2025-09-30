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

	sort(vec.begin(), vec.end()); // 사전 순서 정렬

	// unique를 통해 인접한 중복 원소를 벡터 뒤로 보냄 그러므로 정렬이 먼저 되어야 함
	// unique를 하면 중복 시작부분을 가리킴 (그 후 erase로 해당 부분부터 꼬리 자르기)
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	
	// 문자열 길이는 절대 음수가 될 수 없으니 unsigned타입 size_t 사용 가능하지만, int 또는 long long이 채점에 유리

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


//auto f1 = [](int a, int b) { return a + b; };       // 자동 추론 → int
//auto f2 = [](double a, double b) { return a + b; }; // 자동 추론 → double
//auto f3 = [](bool x) -> double {                    // 명시적 반환
//	if (x) return 1;
//	else return 1.5;
//	};
//
//cout << f1(2, 3) << "\n";    // 5
//cout << f2(2.5, 3.5) << "\n"; // 6.0
//cout << f3(true) << "\n";    // 1.0