#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001

int top = -1; // ������ ����� ������� �ʾҰ� ���� ���ΰ� ����ִ� ��쿡 ���� ����� Ȱ������ �ʾ����� -1�� �ƴϾ ��

char stack[MAX] = { 0 }; // ������ �迭
char s[MAX] = { 0 }; // ù ��°�� �Է¹��� �迭
char t[MAX] = { 0 }; // �� ��°�� �Է¹��� �迭

int main(void)
{
	int i, j, result = 0; // for���� if�� �۵��� ���� ����

	while (1) 
	{
		scanf("%s %s", s, t); // 2���� ���ڿ� �Է�

		top = -1; // ���� �ʱ�ȭ
		result = 0; // ���� �ʱ�ȭ

		if (strlen(s) >= MAX || strlen(t) >= MAX) // s�� t�� ���̴� 10���� ���� ����
		{
			return 0;
		}

		for (i = 0; i < strlen(t); i++) // ���ڿ� t���� ����
		{

			stack[++top] = t[i]; // stack�� ���� ����, �迭 ������ ����(���� ����)

			if (top == strlen(s)) // ���ð� s�� ����(s ������ ����)�� ���� ������ �� ����
			{
				for (j = 0; j < strlen(s); j++) // ���ڿ� ���̿� �°� ��
				{
					if (stack[top + j] != s[j]) // ���ڿ� �߰��� �ٸ� �κ��� ������ �ߴ�
					{
						result = 1;
						break;
					}
				}

				if (result == 0) // ���ڿ��� ������ ��ġ�� ��� (for���� ������ �۵��� ���)
				{
					printf("Yes\n");
					break;
				}
			}
		}
		if (result == 1) // �κ� ���ڿ��� �߰ߵ��� ���� ���
		{
			printf("No\n");
		}

		if (strcmp(s, "caseDoesMatter") == 0 && strcmp(t, "CaseDoesMatter") == 0) // ���α׷� ���� ����
		{
			return 0;
		}
	}

	return 0;
}

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

