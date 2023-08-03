#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// C6262���� �߻� -> �迭�� ���������� �ű�� �ذ��
int prime[1100000] = { 0 }; // �Ҽ� �Ǵ� �迭
// ������� ���� Ŀ���� 1003001�� ��µǹǷ� �̸� ���� ������ ũ�� ����

int main(void)
{
	int N; // ���� �Է�
	int i, j; // �Ҽ� �Ǻ� for�� ����
	char string[8]; // 1000000���� �̹Ƿ� �̸� �����ϱ� ���� �迭
	int len = 0; // ���ڿ��� ����
	int k; // �Ӹ���� �Ǵ� for�� ����
	int count = 0; // ���� �Ǵ� ����

	scanf("%d", &N);

	if (N < 1 || N > 1000000)
	{
		return 0;
	}

	prime[0] = prime[1] = 1; // ���� �ʱ�ȭ

	for (i = N; i <= 1100000; i++) // �Ҽ����� �Ǵ� & ������� ���� Ŀ���� 1003001�� ��µǹǷ� �̸� ���� ������ ũ�� ����
	{
		for (j = 2; j * j <= i; j++) // �Ҽ� �Ǻ�
		{
			if (i % j == 0) // ������ ������
			{
				prime[i] = 1; // �Ҽ��� �ƴ�
				break;
			}
		}

		if (prime[i] == 0) // �Ҽ��� ��� �۵�
		{
			sprintf(string, "%d", i); // ���ڸ� ���ڿ��� ��ȯ
			len = strlen(string); // ���ڿ��� ���� �ľ�
			for (k = 0; k < len / 2; k++) // ���ڿ��� ���� ������ �Ǵ�
			{
				if (string[k] != string[len - k - 1]) // ���ڿ��� �հ� �ڿ��� ������� ��
				{
					break;
				}
				else
				{
					count++;
				}
			}

			if (count == len / 2) // ��� ���ǿ� ������ ��� for���� ��������
			{
				printf("%d", i);
				break;
			}
			count = 0; // count ���� �ʱ�ȭ
		}
	}

	return 0;
}