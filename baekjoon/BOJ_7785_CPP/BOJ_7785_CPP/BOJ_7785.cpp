#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

const string ENTER_STATE = "enter";
const string LEAVE_STATE = "leave";

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string name;
	string state;

	unordered_set<string> log;

	for (int i = 0; i < n; i++)
	{
		cin >> name >> state;

		if (state.compare(ENTER_STATE) == 0)
		{
			log.insert(name);
		}

		if (state.compare(LEAVE_STATE) == 0)
		{
			log.erase(name);
		}
	}

	vector<string> result(log.begin(), log.end());

	sort(result.rbegin(), result.rend());

	for (const auto& name : result)
	{
		cout << name << '\n';
	}

	return 0;
}