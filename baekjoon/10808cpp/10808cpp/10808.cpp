//백준 문제 10808 c++
//알파벳 소문자로만 이루어진 단어 S가 주어진다.각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 단어 S가 주어진다.단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.
//
//출력
//단어에 포함되어 있는 a의 개수, b의 개수, …, z의 개수를 공백으로 구분해서 출력한다.

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