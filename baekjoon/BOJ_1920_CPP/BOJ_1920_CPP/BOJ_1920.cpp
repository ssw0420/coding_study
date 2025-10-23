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
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end()); // A를 정렬해야 binary_search 사용 가능

    int M;
    cin >> M;

    while (M--)
    {
        int x;
        cin >> x;
        cout << (binary_search(A.begin(), A.end(), x) ? "1\n" : "0\n"); // 이진 탐색 활용으로 시간복잡도 낮음
    }

    return 0;
}
