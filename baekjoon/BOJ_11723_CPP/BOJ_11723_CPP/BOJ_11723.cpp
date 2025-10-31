#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;       // 명령 개수
    int S = 0;   // 비트마스킹 집합 (1~20)
    cin >> M;

    while (M--)
    {
        string cmd;
        int x;
        cin >> cmd;

        if (cmd == "add")
        {
            cin >> x;
            S |= (1 << x);  // x번째 비트를 1로 켠다.
        }
        else if (cmd == "remove")
        {
            cin >> x;
            S &= ~(1 << x); // x번째 비트를 0으로 끈다.
        }
        else if (cmd == "check")
        {
            cin >> x;
            cout << ((S & (1 << x)) ? 1 : 0) << '\n'; // x번째 비트 확인
        }
        else if (cmd == "toggle")
        {
            cin >> x;
            S ^= (1 << x);  // x번째 비트를 반전
        }
        else if (cmd == "all")
        {
            S = (1 << 21) - 2; // 1~20 비트를 모두 1로 (0번째 비트는 사용X)
        }
        else if (cmd == "empty")
        {
            S = 0; // 전부 끈다.
        }
    }

    return 0;
}
