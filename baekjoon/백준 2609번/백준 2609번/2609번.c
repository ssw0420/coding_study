#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a, b; // �Է¹޴� ��
	int bg, sl; // ū ���� ���� �� ����
	int i; // ����
	int g, l; // �ִ�����, �ּҰ����

	scanf("%d %d", &a, &b);

	if (a > 10000 || b > 10000) // �� ���� 10000�ʰ��� ����
	{
		return 0;
	}

	bg = (a >= b) ? a : b; // ũ�ų� ���� �� ����
	sl = (a <= b) ? a : b; // �۰ų� ���� �� ����



	for (i = 1; i <= sl; i++) // ���� ������ ���� �ݺ� (�ִ�����)
	{
		if (bg % i == 0 && sl % i == 0)
		{
			g = i;
		}
	}

	for (i = bg; ; i++) // ū ������ �ݺ� ���� (�ּҰ����)
	{
		if (i % bg == 0 && i % sl == 0)
		{
			l = i;
			break;
		}
	}

	printf("%d\n%d", g, l); // ����� ���

	return 0;
}