//10828 ����
//����
//������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//����� �� �ټ� �����̴�.
//
//push X : ���� X�� ���ÿ� �ִ� �����̴�.
//pop : ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
//size : ���ÿ� ����ִ� ������ ������ ����Ѵ�.
//empty : ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
//top : ������ ���� ���� �ִ� ������ ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
//�Է�
//ù° �ٿ� �־����� ����� �� N(1 �� N �� 10, 000)�� �־�����.��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����.�־����� ������ 1���� ũ�ų� ����, 100, 000���� �۰ų� ����.������ �������� ���� ����� �־����� ���� ����.
//
//���
//����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.

#include <iostream>
#include <string>

using namespace std;

int stack[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int count = 0;
	int cursor = 0;
	string command;

	cin >> count;
	while (count--) {
		cin >> command;

		if (command == "push") {
			int X = 0;
			cin >> X;
			stack[cursor++] = X;
		} else if (command == "pop") {
			if (cursor == 0) {
				cout << "-1" << endl;
			} else {
				cout << stack[--cursor] << endl; // cursor�� �̹� ���� ĭ�� �����Ƿ� �� ĭ ���� ��
			}
		} else if (command == "size") {
			cout << cursor << endl;
		} else if (command == "empty") {
			cout << (cursor == 0 ? "1" : "0") << endl;
		} else if (command == "top") {
			if (cursor == 0) {
				cout << "-1" << endl;
			} else {
				cout << stack[cursor - 1] << endl;
			}
		}
	}
	return 0;
}