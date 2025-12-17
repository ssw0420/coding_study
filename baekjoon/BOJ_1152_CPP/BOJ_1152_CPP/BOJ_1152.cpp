#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    string s;
    getline(cin, s);

    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            if (i == 0 || s[i - 1] == ' ')
            {
                count++;
            }
        }
    }

    cout << count;

	return 0;
}