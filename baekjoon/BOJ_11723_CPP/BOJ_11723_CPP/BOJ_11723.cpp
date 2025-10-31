#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;       // ��� ����
    int S = 0;   // ��Ʈ����ŷ ���� (1~20)
    cin >> M;

    while (M--)
    {
        string cmd;
        int x;
        cin >> cmd;

        if (cmd == "add")
        {
            cin >> x;
            S |= (1 << x);  // x��° ��Ʈ�� 1�� �Ҵ�.
        }
        else if (cmd == "remove")
        {
            cin >> x;
            S &= ~(1 << x); // x��° ��Ʈ�� 0���� ����.
        }
        else if (cmd == "check")
        {
            cin >> x;
            cout << ((S & (1 << x)) ? 1 : 0) << '\n'; // x��° ��Ʈ Ȯ��
        }
        else if (cmd == "toggle")
        {
            cin >> x;
            S ^= (1 << x);  // x��° ��Ʈ�� ����
        }
        else if (cmd == "all")
        {
            S = (1 << 21) - 2; // 1~20 ��Ʈ�� ��� 1�� (0��° ��Ʈ�� ���X)
        }
        else if (cmd == "empty")
        {
            S = 0; // ���� ����.
        }
    }

    return 0;
}
