#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 최대 크기를 제한
	// 해당 최대 크기에서 모두 탐색하고 크기를 1씩 늘림
	// 중복 있으면 안됨

	string S;
	cin >> S;

	unordered_set<string> st;

	st.reserve(S.size() * (S.size() + 1) / 2);

	for (int len = 1; len <= S.size(); ++len)
	{
		for (int start = 0; start + len <= S.size(); ++start)
		{
			st.insert(S.substr(start, len));
		}
	}

	cout << st.size();

	return 0;
}