#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	char left;
	char right;
};

vector<Node> tree;

void PreOrder(int cur)
{
	cout << char(cur + 'A');

	if (tree[cur].left != '.')
	{
		PreOrder(tree[cur].left - 'A');
	}

	if (tree[cur].right != '.')
	{
		PreOrder(tree[cur].right - 'A');
	}
}

void InOrder(int cur)
{
	if (tree[cur].left != '.')
	{
		InOrder(tree[cur].left - 'A');
	}

	cout << char(cur + 'A');

	if (tree[cur].right != '.')
	{
		InOrder(tree[cur].right - 'A');
	}
}

void PostOrder(int cur)
{
	if (tree[cur].left != '.')
	{
		PostOrder(tree[cur].left - 'A');
	}

	if (tree[cur].right != '.')
	{
		PostOrder(tree[cur].right - 'A');
	}

	cout << char(cur + 'A');
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	tree.assign(N, { '.', '.' });

	for (int i = 0; i < N; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;

		int idx = parent - 'A';
		tree[idx].left = left;
		tree[idx].right = right;
	}

	PreOrder(0);
	cout << '\n';

	InOrder(0);
	cout << '\n';

	PostOrder(0);
	cout << '\n';
	
	return 0;
}