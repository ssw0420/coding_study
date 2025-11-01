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

    // �赵 ���� ��� �Է�
    for (int i = 0; i < N; i++)
    {
        cin >> unheard[i];
    }

    // ���� ���� ��� �Է�
    for (int i = 0; i < M; i++)
    {
        cin >> unseen[i];
    }


    // �� ���� ���� (������)
    sort(unheard.begin(), unheard.end());
    sort(unseen.begin(), unseen.end());

    vector<string> result;
    int i = 0, j = 0;

    // �� �����ͷ� ������ Ž��
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
