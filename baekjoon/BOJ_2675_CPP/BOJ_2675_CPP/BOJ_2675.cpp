#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		int R;
		string S;
		string result;
		cin >> R >> S;

		result.reserve(static_cast<size_t>(R) * S.size());
		for (const char ch : S)
		{
			for (int r = 0; r < R; ++r)
			{
				result.push_back(ch);
			}
			// result.append(R, ch);
		}
		cout << result << '\n';
	}


	return 0;
}