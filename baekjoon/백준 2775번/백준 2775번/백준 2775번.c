#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int room[15][15] = { 0 }; // 0 ~ 14, ������ �迭 ���Ҹ� �����ϱ� ���� �� �� �� ÷�ڴ� 0���� (��,��ũ�� -1)���� ��ȿ
	int i, j; // ��, ȣ ����
	int num; // �Է¹��� ȣ or ��
	int T; // T�� �ݺ�
	int a = 0; // �ݺ� Ƚ�� ����

	scanf("%d", &T); // T�� �ݺ�


	for (j = 0; j <= 14; j++) // 0�� ����� ��
	{
		room[0][j] = j;
	}

	for (i = 1; i <= 14; i++)
	{
		for (j = 1; j <= 14; j++)
		{
			room[i][j] = room[i - 1][j] + room[i][j - 1]; // ex) 203ȣ�� ��� �� = 101ȣ + 102ȣ + 103ȣ = 202ȣ + 103ȣ
		}
	}

	for (a = 0; a < T; a++)
	{
		scanf("%d %d", &i, &j);
		printf("%d\n", room[i][j]);
	}

	return 0;
}