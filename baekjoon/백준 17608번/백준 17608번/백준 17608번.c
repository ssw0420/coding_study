#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 100001 // �ִ� ����

int stack[MAX] = { 0 }; // ������� ���� ���� ����
int h[MAX] = { 0 }; // ������� ����
int top = -1; // ������ �����

int Full()
{
	if (top >= MAX) // ������ �ε��� 0���� ����
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

void push(int data) // ������ �� ���ִ��� �˻��ϰ�, �׷��� �ʴٸ� ���Ҹ� ������ ���� ���κп� �߰�
{
	if (!Full())
	{
		top++;
		stack[top] = data;
	}
}

int pop() // ������ ����ִ��� �˻��ϰ�, �׷��� �ʴٸ� ���� �� ���Ҹ� ��ȯ
{
	if (!Empty())
	{
		return stack[top--];
	}
	return 0;
}

int main(void)
{
	int i = 0; // for�� �۵� ����
	int N = 0; // ����� ����
	int height = 0; // stack���� pop�� ���� �� ��� ����
	int count = 1; // �����ʿ��� ���̴� ������� ����, ù ��° ������ ���̱� ������ �ʱⰪ 1�� ����

	scanf("%d", &N); // ����� ���� �Է�

	if (N < 2 || N > 100000)
	{
		return 0;
	}

	for (i = 0; i < N; i++) // N���� ������� ���̸� ���� �Է¹���
	{
		scanf("%d", &h[i]);

		if (h[i] < 1 || h[i] > 100000)
		{
			return 0;
		}

		push(h[i]); // stack�� ���� (����)
	}

	i = 1;

	while (1)
	{
		height = pop(); // stack�� ����� ���� �ҷ���
		
		if (height > h[N - i]) // ���� ���̺��� ���� ���̰� �� Ŭ ���
		{
			count++; // ���̴� ����� ���� ����
		}

		if (height == 0) // �˻��� ������ ����ִ� ���
		{
			break;
		}
		i++;
	}

	printf("%d", count); // ��� ���

	return 0;
}