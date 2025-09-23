#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num < 2) continue;

        bool isPrime = true;
        for (int j = 2; j * j <= num; j++)
        {
            if (num % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime) result++;
    }
    cout << result;
}