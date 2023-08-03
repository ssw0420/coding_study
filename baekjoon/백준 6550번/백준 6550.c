/*
int Full()
{
	if (top >= MAX - 1) // ������ �ε��� 0���� ����
	{
		return 1;
	}
	return 0;
}

int Empty()
{
	if (top == -1) // ������ ����ִ��� �˻�
	{
		return 1;
	}
	return 0;
}

void push(char data) // ������ �� ���ִ��� �˻��ϰ�, �׷��� �ʴٸ� ���Ҹ� ������ ���� ���κп� �߰�
{
	if (!Full())
	{
		top++;
		stack[top] = data;
	}
}

char pop() // ������ ����ִ��� �˻��ϰ�, �׷��� �ʴٸ� ���� �� ���Ҹ� ��ȯ
{
	if (!Empty())
	{
		return stack[top--];
	}
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001

int top = -1; // stack�� ����ִ� ���

char stack[MAX] = { 0 }; // ������ �迭
char s[MAX] = { 0 }; // ù ��°�� �Է¹��� �迭
char t[MAX] = { 0 }; // �� ��°�� �Է¹��� �迭

int Empty()
{
	if (top == -1) // ������ ����ִ��� �˻�
	{
		return 1;
	}
	return 0;
}

void pop() // ������ ����ִ��� �˻��ϰ�, �׷��� �ʴٸ� top ����
{
	if (!Empty())
	{
		top--;
		return;
	}
}

void push(char data) // ���Ҹ� ������ ���� ���κп� �߰�
{
		top++;
		stack[top] = data;
}

int main(void)
{
	int index = 0;
	int i;

	while (scanf("%s %s", s, t) != EOF) // ���ڿ� �Է�
	{
		top = -1; // �ʱ�ȭ
		index = 0;

		for (i = 0; i < strlen(s); i++)
		{
			push(s[i]); // s�� �Է¹��� ��� ���ڸ� stack�� ����
		}

		for (i = 0; i <= strlen(t); i++) // ���ڿ� ���� t���� �ݺ�
		{
			if (stack[index] == t[i])
			{
				pop();
				index++;
			}
		}
		if (Empty() == 1) // �κ� ���ڿ��� �ش��ϴ� ���
		{
			printf("Yes\n");
		}
		else // �׷��� ���� ���
		{
			printf("No\n");
		}
	}
	return 0;
}

/*
		if (strcmp(s, "caseDoesMatter") == 0 && strcmp(t, "CaseDoesMatter") == 0) // ���α׷� ���� ����
		{
			return 0;
		}
*/