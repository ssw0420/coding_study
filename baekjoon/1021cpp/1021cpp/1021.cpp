//1021�� ȸ���ϴ� ť
//
//����
//�����̴� N���� ���Ҹ� �����ϰ� �ִ� ����� ��ȯ ť�� ������ �ִ�.�����̴� �� ť���� �� ���� ���Ҹ� �̾Ƴ����� �Ѵ�.
//
//�����̴� �� ť���� ������ ���� 3���� ������ ������ �� �ִ�.
//
//ù ��° ���Ҹ� �̾Ƴ���.�� ������ �����ϸ�, ���� ť�� ���Ұ� a1, ..., ak�̾��� ���� a2, ..., ak�� ���� �ȴ�.
//�������� �� ĭ �̵���Ų��.�� ������ �����ϸ�, a1, ..., ak�� a2, ..., ak, a1�� �ȴ�.
//���������� �� ĭ �̵���Ų��.�� ������ �����ϸ�, a1, ..., ak�� ak, a1, ..., ak - 1�� �ȴ�.
//ť�� ó���� ���ԵǾ� �ִ� �� N�� �־�����.�׸��� �����̰� �̾Ƴ����� �ϴ� ������ ��ġ�� �־�����. (�� ��ġ�� ���� ó�� ť������ ��ġ�̴�.) �̶�, �� ���Ҹ� �־��� ������� �̾Ƴ��µ� ��� 2��, 3�� ������ �ּڰ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//ù° �ٿ� ť�� ũ�� N�� �̾Ƴ����� �ϴ� ���� ���� M�� �־�����.N�� 50���� �۰ų� ���� �ڿ����̰�, M�� N���� �۰ų� ���� �ڿ����̴�.��° �ٿ��� �����̰� �̾Ƴ����� �ϴ� ���� ��ġ�� ������� �־�����.��ġ�� 1���� ũ�ų� ����, N���� �۰ų� ���� �ڿ����̴�.
//
//���
//ù° �ٿ� ������ ������ ����Ѵ�.

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> targets(M);
    for (int i = 0; i < M; ++i) {
        cin >> targets[i];
    }

    deque<int> dq;
    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    int total_operations = 0;

    for (int i = 0; i < M; ++i) {
        int target = targets[i];
        // ���� deque���� target�� �ε��� ã��
        int idx = 0;
        for (; idx < dq.size(); ++idx) {
            if (dq[idx] == target) {
                break;
            }
        }

        // �������� ȸ���ϴ� Ƚ��
        int left_rotations = idx;
        // ���������� ȸ���ϴ� Ƚ��
        int right_rotations = dq.size() - idx;

        if (left_rotations <= right_rotations) {
            // �������� ȸ��
            for (int j = 0; j < left_rotations; ++j) {
                int front = dq.front();
                dq.pop_front();
                dq.push_back(front);
                total_operations++;
            }
        }
        else {
            // ���������� ȸ��
            for (int j = 0; j < right_rotations; ++j) {
                int back = dq.back();
                dq.pop_back();
                dq.push_front(back);
                total_operations++;
            }
        }

        // ù ��° ���� ����
        dq.pop_front();
    }

    cout << total_operations;

    return 0;
}