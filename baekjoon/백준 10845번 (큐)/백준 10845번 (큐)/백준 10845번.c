#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int queue[10001] = { 0 };
int first = 0; // queue�� ����ִ� ����
int count = 0;
int rear = 0;

int empty() // queue�� ����ִ� �� Ȯ��
{
	if (count == 0)
	{
		return 1;
	}
	else if (count != 0)
	{
		return 0;
	}
}

void push(int num) // push x ����
{
	queue[rear++] = num;
	count++;
}

int pop() // pop ����
{
	if (empty())
	{
		return -1;
	}
	else if (!empty())
	{
		count--;
		return queue[first++];
	}
}

int size() // size ���
{
	return count;
}


int front() // queue�� ���� �տ� �ִ� ���� ���
{
	if (empty())
	{
		return -1;
	}
	else if (!empty())
	{
		return queue[first];
	}
}

int back() // queue�� ���� �ڿ� �ִ� ���� ���
{
	if (empty())
	{
		return -1;
	}
	else if (!empty())
	{
		return queue[rear - 1];
	}
}

int main(void)
{
	int N = 0; // ����� ��
	int num = 0; // ��ɿ��� �־����� ����
	int i = 0; // for�� ����
	char str[6] = { 0 }; // ��� �Է�

	scanf("%d", &N);

	if (N < 1 || N > 10000) // ����� �� ���� ����
	{
		return 0;
	}

	for (i = 0; i < N; i++)
	{
		scanf("%s", str); // ����� �Է¹���

		if (strcmp(str, "push") == 0) // push x ���� �۵�
		{
			scanf("%d", &num);
			push(num);
			if (num < 1 || num > 100000) // ���� ���� ����
			{
				return 0;
			}
		}
		else if (strcmp(str, "pop") == 0)
		{
			printf("%d\n", pop());
		}
		else if (strcmp(str, "size") == 0)
		{
			printf("%d\n", size());
		}
		else if (strcmp(str, "empty") == 0)
		{
			printf("%d\n", empty());
		}
		else if (strcmp(str, "front") == 0)
		{
			printf("%d\n", front());
		}
		else if (strcmp(str, "back") == 0)
		{
			printf("%d\n", back());
		}
		else
		{
			return 0;
		}
	}

	return 0;
}