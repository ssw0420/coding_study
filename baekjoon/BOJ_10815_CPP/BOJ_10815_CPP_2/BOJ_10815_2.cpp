#include <iostream>
#include <unordered_set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    unordered_set<int> player_cards;
    for (int i = 0; i < N; i++)
    {
        int card;
        cin >> card;
        player_cards.insert(card);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int target;
        cin >> target;

        if (player_cards.find(target) != player_cards.end())
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