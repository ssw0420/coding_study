#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	const vector<string> patterns =
	{
		"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
	};

	int count = 0;

	for (size_t i = 0; i < str.length(); )
	{
		bool isMatched = false;

		for (const auto& p : patterns) // c= -> c- -> dz= -> ... for compare with str and p
		{
			if (i + p.length() <= str.length() && str.compare(i, p.length(), p) == 0) // if same => return 0 => true
			{
				isMatched = true;
				i += p.length();
				break;
			}
		}

		if (!isMatched) i++;

		count++;
	}

	cout << count;

	return 0;
}