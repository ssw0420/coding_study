#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int A, B; // ����
	int i, j; // �����佺�׳׽��� ü�� Ȱ���� ����
	int k; // for�� ����
	int prime = 0; // �Ҽ� �Ǻ� ����
	int count = 0; // ���� D�� �����ϴ� �Ҽ��� ����
	int D; // Ž���� ����

	scanf("%d %d %d", &A, &B, &D);

	if (1 > A || A > B || B > 4000000 || B > A + 2000000 || D < 0 || D > 9)
	{
		return 0;
	}

	for (k = 2; k <= B; k++) // 2���� k�� ������Ŵ
	{
		for (j = k; j <= B; j += k)
		{
			i = j;
			if (i >= A && i <= B) // ���� A���� B����
			{
				while (i != 0)
				{
					if (i % 10 == D) // �������� ����
					{
						count++; // D�� �����ϰ� ���� ��� ����
						break;
					}
					i /= 10; // ���� �ڸ����� �̵�
				}
			}
		}
	}

	printf("%d", count);

	return 0;
}