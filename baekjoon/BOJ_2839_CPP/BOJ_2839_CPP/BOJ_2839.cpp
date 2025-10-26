#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    const int INF = 1e9;
    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (i - 3 >= 0 && dp[i - 3] != INF)
        {
            dp[i] = min(dp[i], dp[i - 3] + 1);
        }
            
        if (i - 5 >= 0 && dp[i - 5] != INF)
        {
            dp[i] = min(dp[i], dp[i - 5] + 1);
        }
 
    }

    if (dp[N] == INF)
    {
        cout << -1;
    }
    else
    {
        cout << dp[N];
    }

    return 0;
}
