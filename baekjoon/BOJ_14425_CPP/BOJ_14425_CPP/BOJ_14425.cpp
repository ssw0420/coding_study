#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	unordered_set<string> s;
	string input;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		s.insert(input);
	}

	int count = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		//auto it = s.find(input);
		if (s.find(input) != s.end())
		{
			count++;
			//string foundString = *it;

			//cout << "찾은 문자열: " << foundString << endl;
				//5 11
				//baekjoononlinejudge
				//startlink
				//codeplus
				//sundaycoding
				//codingsh
				//baekjoon
				//codeplus
				//찾은 문자열 : codeplus
				//codeminus
				//startlink
				//찾은 문자열 : startlink
				//starlink
				//sundaycoding
				//찾은 문자열 : sundaycoding
				//codingsh
				//찾은 문자열 : codingsh
				//codinghs
				//sondaycoding
				//startrink
				//icerink
		}
	}

	cout << count;

	return 0;
}