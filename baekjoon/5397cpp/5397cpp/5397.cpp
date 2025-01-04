//���� 5397��
//����
//â���̴� �������� ��й�ȣ�� ��ġ�� ���ؼ� �����̰� ����ϴ� ��ǻ�Ϳ� Ű�ΰŸ� ��ġ�ߴ�.��ĥ�� ��ٸ� ���� â���̴� �����̰� ��й�ȣ â�� �Է��ϴ� ���ڸ� ���´�.
//
//Ű�ΰŴ� ����ڰ� Ű���带 ���� ����� ��� ����Ѵ�.����, �����̰� ��й�ȣ�� �Է��� ��, ȭ��ǥ�� �齺���̽��� �Է��ص� ��Ȯ�� ��й�ȣ�� �˾Ƴ� �� �ִ�.
//
//�����̰� ��й�ȣ â���� �Է��� Ű�� �־����� ��, �������� ��й�ȣ�� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.�����̴� Ű����� �Է��� Ű�� ���ĺ� �빮��, �ҹ���, ����, �齺���̽�, ȭ��ǥ�̴�.
//
//�Է�
//ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����.�� �׽�Ʈ ���̽��� ���ٷ� �̷���� �ְ�, �����̰� �Է��� ������� ���̰� L�� ���ڿ��� �־�����. (1 �� L �� 1, 000, 000) �����̰� �齺���̽��� �Է��ߴٸ�, '-'�� �־�����.�̶� Ŀ���� �ٷ� �տ� ���ڰ� �����Ѵٸ�, �� ���ڸ� �����.ȭ��ǥ�� �Է��� '<'�� '>'�� �־�����.�̶��� Ŀ���� ��ġ�� ������ �� �ִٸ�, ���� �Ǵ� ���������� 1��ŭ �����δ�.������ ���ڴ� ��й�ȣ�� �Ϻ��̴�.����, ���߿� �齺���̽��� ���ؼ� ���� ���� �ִ�.���� Ŀ���� ��ġ�� ���� �������� �ƴ϶��, Ŀ�� �� Ŀ�� �����ʿ� �ִ� ��� ���ڴ� ���������� �� ĭ �̵��Ѵ�.
//
//���
//�� �׽�Ʈ ���̽��� ���ؼ�, �������� ��й�ȣ�� ����Ѵ�.��й�ȣ�� ���̴� �׻� 0���� ũ��.

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<string> results;
    results.reserve(t);

    while (t--) {
        string input;
        cin >> input;

        stack<char> leftStack;  // Ŀ�� ����
        stack<char> rightStack; // Ŀ�� ������

        for (char c : input) {
            if (c == '<') {
                if (!leftStack.empty()) {
                    rightStack.push(leftStack.top());
                    leftStack.pop();
                }
            }
            else if (c == '>') {
                if (!rightStack.empty()) {
                    leftStack.push(rightStack.top());
                    rightStack.pop();
                }
            }
            else if (c == '-') {
                if (!leftStack.empty()) {
                    leftStack.pop();
                }
            }
            else {
                leftStack.push(c);
            }
        }

        string password;
        // leftStack�� �ùٸ� ������ password�� �߰�
        string leftPart;
        while (!leftStack.empty()) {
            leftPart += leftStack.top();
            leftStack.pop();
        }
        // leftPart�� �������� password�� �߰�
        for (auto it = leftPart.rbegin(); it != leftPart.rend(); ++it) {
            password += *it;
        }
        // rightStack�� ������ ������� password�� �߰�
        while (!rightStack.empty()) {
            password += rightStack.top();
            rightStack.pop();
        }

        results.push_back(password);
    }

    // ��� ����� �� ���� ���
    for (const string& res : results) {
        cout << res << '\n';
    }

    return 0;
}


//#include <iostream>
//
//using namespace std;
//
//int main() {
//    int caseNumber;
//    cin >> caseNumber;
//
//    // char ������ �迭 �Ҵ�
//    char** str_arr = new char* [caseNumber];
//
//    // �� ���ڿ��� �޸� �Ҵ� �� �Է� �б�
//    for (int i = 0; i < caseNumber; ++i) {
//        // �� ���ڿ��� ���� �޸� �Ҵ� (ũ�� 100,000 + 1)
//        str_arr[i] = new char[100001]; // 100,000 + 1 (null)
//        cin >> str_arr[i];
//    }
//
//    // �� ���ڿ� ���
//    for (int i = 0; i < caseNumber; ++i) {
//        cout << str_arr[i] << '\n';
//    }
//
//    // �޸� ����
//    for (int i = 0; i < caseNumber; ++i) {
//        delete[] str_arr[i];
//    }
//    delete[] str_arr;
//
//    return 0;
//}