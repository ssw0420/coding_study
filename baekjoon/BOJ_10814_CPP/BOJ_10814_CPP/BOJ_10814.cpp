#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Member
{
    int age;
    string name;
};

// �� �Լ�: ���̰� �� ���� ����� ������ ���� ��
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

    // ���� ���� ��������, ���� ���̴� �Է� ���� ����
    stable_sort(members.begin(), members.end(), Compare);

    for (const auto& m : members)
        cout << m.age << ' ' << m.name << '\n';

    return 0;
}
