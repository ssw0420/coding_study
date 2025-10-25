#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    unordered_map<long long, int> count;

    // 카드 숫자 등장 횟수 기록
    for (int i = 0; i < N; i++)
    {
        long long x;
        cin >> x;
        count[x]++;
    }

    int M;
    cin >> M;
    vector<long long> query(M);

    for (int i = 0; i < M; i++)
    {
        cin >> query[i];
    }

    // 결과 출력
    for (auto q : query)
    {
        cout << count[q] << ' ';
    }

    return 0;
}
