//���� ���� 10808 c++
//���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S�� �־�����.�� ���ĺ��� �ܾ �� ���� ���ԵǾ� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//ù° �ٿ� �ܾ� S�� �־�����.�ܾ��� ���̴� 100�� ���� ������, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.
//
//���
//�ܾ ���ԵǾ� �ִ� a�� ����, b�� ����, ��, z�� ������ �������� �����ؼ� ����Ѵ�.

//baekjoon
//
//1 1 0 0 1 0 0 0 0 1 1 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0

#include <iostream>
#include <string>
using namespace std;

int main () {
	string str;
	cin >> str;

	int alphabet[26] = {};

	for (int i = 0; i <= str.length(); i++) {
		char charTemp = str[i];
		int intTemp = int(charTemp) - 97;
		alphabet[intTemp] += 1;
	}

	for (int i = 0; i < sizeof(alphabet)/sizeof(int); i++) {
		cout << alphabet[i] << " ";
	}
}