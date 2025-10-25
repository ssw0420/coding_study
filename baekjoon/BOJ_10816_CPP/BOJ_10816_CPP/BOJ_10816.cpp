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

    // ī�� ���� ���� Ƚ�� ���
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

    // ��� ���
    for (auto q : query)
    {
        cout << count[q] << ' ';
    }

    return 0;
}
