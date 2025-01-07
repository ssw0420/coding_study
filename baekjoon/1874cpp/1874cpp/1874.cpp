//1874�� ���� ����
//����
//����(stack)�� �⺻���� �ڷᱸ�� �� �ϳ���, ��ǻ�� ���α׷��� �ۼ��� �� ���� �̿�Ǵ� �����̴�.������ �ڷḦ �ִ�(push) �Ա��� �ڷḦ �̴�(pop) �Ա��� ���� ���� ���߿� �� �ڷᰡ ���� ���� ������(LIFO, Last in First out) Ư���� ������ �ִ�.
//
//1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν�, �ϳ��� ������ ���� �� �ִ�.�̶�, ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ű���� �Ѵٰ� ����.������ ������ �־����� �� ������ �̿��� �� ������ ���� �� �ִ��� ������, �ִٸ� � ������ push�� pop ������ �����ؾ� �ϴ����� �˾Ƴ� �� �ִ�.�̸� ����ϴ� ���α׷��� �ۼ��϶�.
//
//�Է�
//ù �ٿ� n(1 �� n �� 100, 000)�� �־�����.��° �ٺ��� n���� �ٿ��� ������ �̷�� 1�̻� n������ ������ �ϳ��� ������� �־�����.���� ���� ������ �� �� ������ ���� ����.
//
//���
//�Էµ� ������ ����� ���� �ʿ��� ������ �� �ٿ� �� ���� ����Ѵ�.push������ + ��, pop ������ - �� ǥ���ϵ��� �Ѵ�.�Ұ����� ��� NO�� ����Ѵ�.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> stack; // ���� ����
    string output = ""; // ���� ���
    int current = 1; // ���� push�� ����

    bool isPossible = true;

    for (int i = 0; i < n; ++i) {
        if (arr[i] >= current) {
            // �ʿ��� ���ڱ��� push
            while (current <= arr[i]) {
                stack.push_back(current);
                output += "+\n";
                current++;
            }
            // pop
            stack.pop_back();
            output += "-\n";
        }
        else {
            // ������ �ֻ�ܰ� ���� ������ ���� ��
            if (stack.empty() || stack.back() != arr[i]) {
                isPossible = false;
                break;
            }
            else {
                stack.pop_back();
                output += "-\n";
            }
        }
    }

    if (isPossible) {
        cout << output;
    }
    else {
        cout << "NO";
    }

    return 0;
}