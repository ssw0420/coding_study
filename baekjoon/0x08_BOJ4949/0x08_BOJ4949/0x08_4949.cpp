#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		string a;
		getline(cin, a);

		if (a == ".") break;

		stack<char> s;
		bool isValid = true; // .만 있어도 true 반환하기 때문에 초기값 true로 설정
		for (char c : a)
		{
			if (c == '(' || c == '[')
			{
				s.push(c);
			}
			else if (c == ')')
			{
				if (s.empty() || s.top() != '(') // empty를 먼저 확인해야 runtime error가 발생하지 않음
				{
					isValid = false;
					break;
				}
				s.pop();
			}
			else if (c == ']')
			{
				if (s.empty() || s.top() != '[')
				{
					isValid = false;
					break;
				}
				s.pop();
			}
		}

		if (!s.empty())
		{
			isValid = false;
		}

		if (isValid)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
		
	}
}