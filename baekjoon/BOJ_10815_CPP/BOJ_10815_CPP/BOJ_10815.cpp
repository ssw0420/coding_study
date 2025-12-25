#include <iostream>
#include <vector>
#include <algorithm> // sort, binary_search

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> player_cards(N);

	for (int i = 0; i < N; i++)
	{
		cin >> player_cards[i];
	}

	sort(player_cards.begin(), player_cards.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int select;
		cin >> select;

		if (binary_search(player_cards.begin(), player_cards.end(), select))
		{
			cout << 1 << " ";
		}
		else
		{
			cout << 0 << " ";
		}
	}

	return 0;
}