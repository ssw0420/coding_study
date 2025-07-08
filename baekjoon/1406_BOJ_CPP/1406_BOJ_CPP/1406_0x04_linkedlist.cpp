#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

//const int MX = 600005;
//int dat[MX], pre[MX], nxt[MX];
//int unused = 1;

//void InsertAtNext(int addr, int num)
//{
//	dat[unused] = num; // 인덱스에 실제 값 저장
//	pre[unused] = addr; // 새 노드의 이전 노드는 addr
//	nxt[unused] = nxt[addr]; // 새 노드의 다음 노드는 addr의 원래 다음 노드
//	// 기존 addr의 다음 노드가 있다면, 그 노드의 pre를 새 노드로 갱신
//	if (nxt[addr] != -1)
//	{
//		pre[nxt[addr]] = unused;
//	}
//	nxt[addr] = unused; // addr의 다음 노드를 새 노드로 연결
//	unused++; // 다음 삽입을 위해 인덱스 증가
//}
//
//void Erase(int addr)
//{
//	nxt[pre[addr]] = nxt[addr]; // 앞 노드가 뒷 노드를 가리킴
//	if (nxt[addr] != -1)
//	{
//		pre[nxt[addr]] = pre[addr]; // 뒷 노드가 앞 노드를 가리킴
//	}
//}

//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	fill(pre, pre + MX, -1);
//	fill(nxt, nxt + MX, -1);
//
//	cin >> 
//
//	return 0;
//}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string init_str;
	list<char> L;
	
	cin >> init_str;

	for (auto c : init_str)
	{
		L.push_back(c);
	}

	auto cursor = L.end();
	int q;
	cin >> q;
	while (q--)
	{
		char op;
		cin >> op;

		if (op == 'P')
		{
			char add;
			cin >> add;
			L.insert(cursor, add);
		}
		else if (op == 'L')
		{
			if (cursor != L.begin())
			{
				cursor--;
			}
		}
		else if (op == 'D')
		{
			if (cursor != L.end())
			{
				cursor++;
			}
		}
		else
		{
			if (cursor != L.begin())
			{
				cursor--;
				cursor = L.erase(cursor);
			}
		}
	}

	for (auto c : L)
	{
		cout << c;
	}

	return 0;
}