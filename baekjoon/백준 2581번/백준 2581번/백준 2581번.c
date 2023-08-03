#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int i, j, k; // �Ҽ��� ã�� ���� ����
	int num; // i�� j�� ���� ���� ������ ����
	int M, N; // �Է¹��� ��
	int sum = 0, min = 0; // ��, �ּڰ�
	int all[10001] = { 0 }; // 1~10000 ���� �˻��ϱ� ���� �迭

	scanf("%d %d", &M, &N);

	if (M > 10000 || N > 10000)
	{
		return 0;
	}

	all[0] = 1, all[1] = 1; // 0�� 1�� ���� �����ص�

	for (i = 2; i <= N; i++) // N���� for�� �ݺ�
	{
		for (num = 2, j = i; num <= N; j++) // �迭�� ���� num�� 2���� N���� Ŀ�� �� �ְ� ����
		{
			num = i * j; // num�� i�� ���� Ŀ���� ����j�� ���� ���� ����
			
			if (num >= M && num <= N)
			{
					all[num] = 1; // �迭�� 1�� ������ => �Ҽ�
			}
		}
	}

	for (k = M; k < N + 1; k++) // M���� N������ �Ҽ��� Ž��
	{
		if (all[k] == 0)
		{
			sum += k; // �Ҽ��� ���� ����

			if (min == 0) // ���� �ȿ� ������ �� if���� �۵��ϵ��� ����
			{
				min = k; // min�� k���� �ο�
			}
		}
	}

	if (sum == 0) // �Ҽ��� ���� ���
	{
		printf("-1");
	}
	else // �Ҽ��� ���� ���
	{
		printf("%d\n%d\n", sum, min);
	}

	return 0;
}