//�� ��ȣ
//����
//�ټ��̴� �������� ������ ���� �̻�Դ�.�ټ��̴� �ڱ� �� ��ȣ�� ���� �ö�ƽ ���ڷ� ���� ���̷��� �Ѵ�.
//
//�ټ����� ���������� �ö�ƽ ���ڸ� �� ��Ʈ�� �Ǵ�.�� ��Ʈ���� 0������ 9������ ���ڰ� �ϳ��� ����ִ�.�ټ����� �� ��ȣ�� �־����� ��, �ʿ��� ��Ʈ�� ������ �ּڰ��� ����Ͻÿ�. (6�� 9�� ����� �̿��� �� �ְ�, 9�� 6�� ����� �̿��� �� �ִ�.)
//
//�Է�
//ù° �ٿ� �ټ����� �� ��ȣ N�� �־�����.N�� 1, 000, 000���� �۰ų� ���� �ڿ����̴�.
//
//���
//ù° �ٿ� �ʿ��� ��Ʈ�� ������ ����Ѵ�.


// 6�� 9 ������
// ��Ʈ ���� 10���� ����

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// ������ �󵵼��� ���� �Լ�
void countDigits(const string& roomNumber, int digitCount[]) {
    for (char ch : roomNumber) {
        if (ch >= '0' && ch <= '9') {
            digitCount[ch - '0']++;
        }
    }
}

// 6�� 9�� �󵵼��� �����ϴ� �Լ�
int adjustSixNine(int digitCount[]) {
    int six_nine_count = digitCount[6] + digitCount[9];
    int sets_for_six_nine = ceil(six_nine_count / 2.0);
    digitCount[6] = sets_for_six_nine;
    digitCount[9] = 0;

    return sets_for_six_nine;
}

int main() {
    string roomNumber;
    cin >> roomNumber;

    int digitCount[10] = { 0 };

    countDigits(roomNumber, digitCount);
    adjustSixNine(digitCount);

    int max_sets = *max_element(digitCount, digitCount + 10);

    cout << max_sets;

    return 0;
}
