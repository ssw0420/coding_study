#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Member
{
    int age;
    string name;
};

// 비교 함수: 나이가 더 작은 사람이 앞으로 오게 함
bool Compare(const Member& a, const Member& b)
{
    return a.age < b.age;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Member> members(N);

    for (int i = 0; i < N; i++)
        cin >> members[i].age >> members[i].name;

    // 나이 기준 오름차순, 같은 나이는 입력 순서 유지
    stable_sort(members.begin(), members.end(), Compare);

    for (const auto& m : members)
        cout << m.age << ' ' << m.name << '\n';

    return 0;
}
