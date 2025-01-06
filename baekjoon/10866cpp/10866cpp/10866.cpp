//10866�� ��
//����
//������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//����� �� ���� �����̴�.
//
//push_front X : ���� X�� ���� �տ� �ִ´�.
//push_back X : ���� X�� ���� �ڿ� �ִ´�.
//pop_front : ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�.����, ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
//pop_back : ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�.����, ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
//size : ���� ����ִ� ������ ������ ����Ѵ�.
//empty : ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
//front : ���� ���� �տ� �ִ� ������ ����Ѵ�.���� ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
//back : ���� ���� �ڿ� �ִ� ������ ����Ѵ�.���� ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
//�Է�
//ù° �ٿ� �־����� ����� �� N(1 �� N �� 10, 000)�� �־�����.��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����.�־����� ������ 1���� ũ�ų� ����, 100, 000���� �۰ų� ����.������ �������� ���� ����� �־����� ���� ����.
//
//���
//����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.

#include <iostream>
#include <string>

using namespace std;


const int MAX_SIZE = 20000;
int deque[MAX_SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;


    // �迭�� �߰��� ���������� ����
    int front = MAX_SIZE / 2;
    int back = MAX_SIZE / 2;

    while (count--) {
        string command;
        cin >> command;

        if (command == "push_front") {
            int X;
            cin >> X;
            deque[--front] = X;
        }
        else if (command == "push_back") {
            int X;
            cin >> X;
            deque[back++] = X;
        }
        else if (command == "pop_front") {
            if (front == back) {
                cout << "-1\n";
            }
            else {
                cout << deque[front++] << "\n";
            }
        }
        else if (command == "pop_back") {
            if (front == back) {
                cout << "-1\n";
            }
            else {
                cout << deque[--back] << "\n";
            }
        }
        else if (command == "size") {
            cout << (back - front) << "\n";
        }
        else if (command == "empty") {
            cout << ((front == back) ? "1" : "0") << "\n";
        }
        else if (command == "front") {
            if (front == back) {
                cout << "-1\n";
            }
            else {
                cout << deque[front] << "\n";
            }
        }
        else if (command == "back") {
            if (front == back) {
                cout << "-1\n";
            }
            else {
                cout << deque[back - 1] << "\n";
            }
        }
    }
    return 0;
}