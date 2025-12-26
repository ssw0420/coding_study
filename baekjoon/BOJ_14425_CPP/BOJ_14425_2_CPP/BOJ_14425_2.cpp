#include <iostream>
#include <string>

using namespace std;

constexpr int ALPHABET_SIZE = 26;

struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE];

	bool isEnd;

	TrieNode() : isEnd(false)
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			children[i] = nullptr;
		}
	}

	~TrieNode()
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			if (children[i]) delete children[i];
		}
	}

	void insert(const string& word)
	{
		TrieNode* curr = this;
		
		for (char c : word)
		{
			int index = c - 'a';

			if (curr->children[index] == nullptr)
			{
				curr->children[index] = new TrieNode();
			}

			curr = curr->children[index];
		}

		curr->isEnd = true;
	}

	bool find(const string& word)
	{
		TrieNode* curr = this;
		for (char c : word)
		{
			int index = c - 'a';

			if (curr->children[index] == nullptr)
			{
				return false;
			}
			curr = curr->children[index];
		}

		return curr->isEnd;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	TrieNode* root = new TrieNode();
	
	string input;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		root->insert(input);
	}

	int count = 0;
	
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		if (root->find(input))
		{
			count++;
		}
	}

	cout << count;
	delete root;

	return 0;
}