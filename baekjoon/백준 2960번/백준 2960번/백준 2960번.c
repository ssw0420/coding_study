// �����佺�׳׽��� ü �˰���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N, K; // �Է¹��� �� ��
	int num[1001] = { 0 }; // �迭�� �̿��Ͽ� 1000���� Ȯ��
	int i, j; // ����
	int count = 0; // ������ ������ ����

	scanf("%d %d", &N, &K);

	if (K > N && N > 1000)
	{
		return 0;
	}

	for (i = 2; i <= N; i++) // 2���� i�� ������Ŵ
	{
		for (j = i; j <= N; j += i) // i�� ����� �ش��ϴ� ���� Ȯ��
		{
			if (num[j] == 0) // �Ҽ��� �ƴҰ�츸 ����
			{
				num[j] = 1; // �Ҽ��� ��� �迭�� ���� ��ȯ
				count++; // �� ��°�� ������ �������� Ȯ��

				if (count == K) // ������ ���� ��ġ�� ��ġ�� ���
				{
					printf("%d\n", j);
					return 0;
				}
			}
		}
	}

	return 0;
}