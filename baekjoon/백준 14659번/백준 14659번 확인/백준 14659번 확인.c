#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1000001
int height[MAX] = { 0 }; // �ִ� ���� 100000

int main()
{
	int N = 0; // ���츮�� �� �� Ȱ������ ��
	int last = 0; // ���� óġ ��
	int result = 0; // ���� óġ�� ��
	int count = 1; // ���츮 �� üũ
	int next = 0; // ���� ���츮���� ��

	scanf("%d", &N); // ���츮�� �� �� Ȱ������ �� �Է�

	if (N < 1 || N > 30000) // N�� ���� ����
	{
		return 0;
	}

	for (int i = 0; i < N; i++) // N�� �ݺ�
	{
		scanf("%d", &height[i]); // ���츮�� ���� �Է�
		if (height[i] == height[i - 1])
		{
			return 0;
		}
	}

	for (int i = 0; i < N - 1; i++) // ������ Ȱ���̴� óġ�� ���� ���� ����
	{
		if (height[i] != 0) // ���� ���츮���� �� ���� ���̿��� ���̰��� ������� ���� ��츸 while���� �۵��ϵ��� ��
		{
			count = 1; // �ٷ� ���� ���� ���츮�� ���ϱ� ���� count �ʱ�ȭ
			while (height[i] > height[i + count]) // count�� �������� ���� ���츮�� �̵���
			{
				if (height[i + count] == 0)
				{
					break; // ���ѷ��� ����
				}
				height[i + count] = 0; // while�� �۵� Ƚ���� ���̱� ���� ���츮 ���� ����
				result++; // ���� óġ�� �� ����
				count++; // ���� ���츮�� �̵�
			}
		}

		if (result > last) // ���� Ȱ���̰� óġ�� ���� ���� ���ݱ��� �ְ� Ȱ���̰� óġ�� ���� ��
		{
			last = result; // ��� �� ����� ����
		}
		result = 0; // ���� óġ �� �ʱ�ȭ
	}
	printf("%d", last); // ��� ���
}

/*
				if (height[i + count] == 0)
				{
					break;
				}

				height[i + count] = 0;
*/