#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

//const int MX = 600005;
//int dat[MX], pre[MX], nxt[MX];
//int unused = 1;

//void InsertAtNext(int addr, int num)
//{
//	dat[unused] = num; // �ε����� ���� �� ����
//	pre[unused] = addr; // �� ����� ���� ���� addr
//	nxt[unused] = nxt[addr]; // �� ����� ���� ���� addr�� ���� ���� ���
//	// ���� addr�� ���� ��尡 �ִٸ�, �� ����� pre�� �� ���� ����
//	if (nxt[addr] != -1)
//	{
//		pre[nxt[addr]] = unused;
//	}
//	nxt[addr] = unused; // addr�� ���� ��带 �� ���� ����
//	unused++; // ���� ������ ���� �ε��� ����
//}
//
//void Erase(int addr)
//{
//	nxt[pre[addr]] = nxt[addr]; // �� ��尡 �� ��带 ����Ŵ
//	if (nxt[addr] != -1)
//	{
//		pre[nxt[addr]] = pre[addr]; // �� ��尡 �� ��带 ����Ŵ
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