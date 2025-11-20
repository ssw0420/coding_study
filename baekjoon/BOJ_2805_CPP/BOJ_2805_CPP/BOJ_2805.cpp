#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<long long> tree(N);
    for (int i = 0; i < N; i++)
    {
        cin >> tree[i];
    }

    long long left = 0;
    long long right = *max_element(tree.begin(), tree.end());
    long long answer = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long total = 0;

        for (long long h : tree)
        {
            if (h > mid)
            {
                total += (h - mid);
            }
        }

        // M 이상 잘렸는지 확인
        if (total >= M)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer;
    return 0;
}
