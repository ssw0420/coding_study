#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> unheard(N);
    vector<string> unseen(M);

    // 듣도 못한 사람 입력
    for (int i = 0; i < N; i++)
    {
        cin >> unheard[i];
    }

    // 보도 못한 사람 입력
    for (int i = 0; i < M; i++)
    {
        cin >> unseen[i];
    }


    // 두 벡터 정렬 (사전순)
    sort(unheard.begin(), unheard.end());
    sort(unseen.begin(), unseen.end());

    vector<string> result;
    int i = 0, j = 0;

    // 투 포인터로 교집합 탐색
    while (i < N && j < M)
    {
        if (unheard[i] == unseen[j])
        {
            result.push_back(unheard[i]);
            i++;
            j++;
        }
        else if (unheard[i] < unseen[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    cout << result.size() << '\n';
    for (auto& name : result)
    {
        cout << name << '\n';
    }

    return 0;
}
