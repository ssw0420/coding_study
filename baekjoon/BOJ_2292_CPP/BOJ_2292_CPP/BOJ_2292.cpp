#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long count = 1;
    long long range = 1;

    while (N > range)
    {
        range += 6 * count;
        count++;
    }

    cout << count;
    return 0;
}