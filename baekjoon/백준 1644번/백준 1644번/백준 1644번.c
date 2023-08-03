// �Ҽ��� ������

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int prime[4000001] = { 0 };

int main(void)
{
	int N; // �Է¹��� ��
	int i, j; // for�� ��� ����
	int sum = 0; // ���� ���ϱ� ���� ����
	int count = 0; // ����� ��

	scanf("%d", &N);

	if (1 > N || N > 4000000)
	{
		return 0;
	}

	prime[0] = prime[1] = 1; // ����ó��

	// �Ҽ� Ž��
	for (i = 2; i * i <= N; i++) // 2���� i�� ������Ŵ
	{
		if (prime[i] == 1) // �Ҽ��̸� ���� ���ڷ� ����
		{
			continue;
		}
		for (j = i * i; j <= N; j += i) // �Ҽ��� ����� �Ҽ��� �ƴ� -> prime[]�迭 ���� ���� ��ȯ
		{
			prime[j] = 1; // �Ҽ��� �ƴ� ��� �迭�� ���� ��ȯ
		}
	}


	// �Ҽ� �� ���ϱ�
	for (i = 2; i <= N; i++) // i�� N�� �� ������ �ݺ�
	{
		if (prime[i] == 0) // �Ҽ��� ���
		{
			sum = i; // ���� �����ϴ� ������ i�� ����
			for (j = i + 1; j <= N; j++) // ���� ������ �÷����� �ݺ�
			{
				if (prime[j] == 0) // �Ҽ��� ���
				{
					sum += j; // sum + j 

					if (sum == N) // ���� N �ΰ��
					{
						count++; // ����� �� ����
						break;
					}
					else if (sum > N) // ���� N�� �ʰ��ϴ� ���
					{
						break;
					}
				}
			}
		}
	}

	if (prime[N] == 0) // i�� N�̸� �Ҽ��� ���
	{
		count++; // ����� �� ����
	}
	printf("%d", count);

	return 0;
}