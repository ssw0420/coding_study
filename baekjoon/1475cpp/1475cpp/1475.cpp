//방 번호
//문제
//다솜이는 은진이의 옆집에 새로 이사왔다.다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.
//
//다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다.한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다.다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)
//
//입력
//첫째 줄에 다솜이의 방 번호 N이 주어진다.N은 1, 000, 000보다 작거나 같은 자연수이다.
//
//출력
//첫째 줄에 필요한 세트의 개수를 출력한다.


// 6과 9 연관성
// 세트 내에 10개의 숫자

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// 숫자의 빈도수를 세는 함수
void countDigits(const string& roomNumber, int digitCount[]) {
    for (char ch : roomNumber) {
        if (ch >= '0' && ch <= '9') {
            digitCount[ch - '0']++;
        }
    }
}

// 6과 9의 빈도수를 조정하는 함수
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
