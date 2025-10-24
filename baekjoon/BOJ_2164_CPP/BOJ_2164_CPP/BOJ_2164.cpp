#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N;
	cin >> N;

	long long tempCard;

	deque<long long> card;
	
	for (long long i = N; i > 0; i--)
	{
		card.push_front(i);
	}

	while (card.size() > 1)
	{
		card.pop_front();
		tempCard = card.front();
		card.pop_front();
		card.push_back(tempCard);
	}
	
	cout << card.front();
	return 0;
}