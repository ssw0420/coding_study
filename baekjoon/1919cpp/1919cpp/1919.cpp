//1919 �ֳʱ׷� �����
//����
//�� ���� �ܾ ö���� ������ �ڹٲپ� ������ �� ���� ��, �׷��� �� �ܾ ���� �ֳʱ׷� ���迡 �ִٰ� �Ѵ�.���� ��� occurs ��� ���� �ܾ�� succor �� ���� �ֳʱ׷� ���迡 �ִµ�, occurs�� �� ���ڵ��� ������ �� �ٲٸ� succor�� �Ǳ� �����̴�.
//
//�� ��, dared�� bread�� ���� �ֳʱ׷� ���迡 ���� �ʴ�.������ dared���� �� ���� d�� �����ϰ�, bread���� ���� ���� b�� �����ϸ�, ared�� read��� ���� �ֳʱ׷� ���迡 �ִ� �ܾ ���� �ȴ�.
//
//�� ���� ���� �ܾ �־����� ��, �� �ܾ ���� �ֳʱ׷� ���迡 �ֵ��� ����� ���ؼ� �����ؾ� �ϴ� �ּ� ������ ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.���ڸ� ������ ������ �ƹ� ��ġ�� �ִ� ���ڵ��� ������ �� �ִ�.
//
//�Է�
//ù° �ٰ� ��° �ٿ� ���� �ܾ �ҹ��ڷ� �־�����.������ ���̴� 1, 000�ڸ� ���� ������, ��� �� ���ڷ� �̷���� �ܾ �־�����.
//
//���
//ù° �ٿ� ���� ����Ѵ�.

#include <iostream>
#include <string>

using namespace std;

int main() {
	string firstString, secondString, resultString;
	int firstCount = 0;
	int secondCount = 0;
	int resultCount = 0;
	cin >> firstString >> secondString;


	for (char firstChar : firstString) {
		for (char secondChar : secondString) {
			if (firstChar == secondChar) {
				firstString.replace(firstCount, 1, "A");
				secondString.replace(secondCount, 1, "A");
				
				break;
			}
			secondCount++;
		}
		firstCount++;
		secondCount = 0;
	}

	resultString = firstString + secondString;
	for (char resultChar : resultString) {
		if (resultChar == 'A') {
			resultCount++;
		}
	}
	
	cout << resultString.length() -  resultCount;

	return 0;
}


//�ٸ� ���
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	string firstString, secondString;
//	cin >> firstString >> secondString;
//
//	// ���ĺ� �ҹ��� 26���� ���� �� �迭
//	vector<int> freqFirst(26, 0);
//	vector<int> freqSecond(26, 0);
//
//	// ù ��° ���ڿ��� �� ���
//	for (char c : firstString) {
//		freqFirst[c - 'a']++;
//	}
//
//	// �� ��° ���ڿ��� �� ���
//	for (char c : secondString) {
//		freqSecond[c - 'a']++;
//	}
//
//	// �� ������ �� ���
//	int deletions = 0;
//	for (int i = 0; i < 26; i++) {
//		deletions += abs(freqFirst[i] - freqSecond[i]);
//	}
//
//	cout << deletions;
//
//	return 0;
//}
