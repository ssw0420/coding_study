#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }

    sort(P.begin(), P.end()); // SJF: 처리시간 짧은 순으로 정렬

    int sum = 0;
    int total = 0;

    for (int i = 0; i < N; i++)
    {
        sum += P[i];     // 지금 사람까지의 누적 대기시간
        total += sum;    // 전체 누적합
    }

    cout << total;

    return 0;
}