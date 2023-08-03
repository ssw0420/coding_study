#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int A, B; // ����
    int i; // for�� ����
    int j; // �����佺�׳׽��� ü�� Ȱ���� ����
    int prime = 1; // �Ҽ� �Ǻ� ����
    int count = 0; // ���� D�� �����ϴ� �Ҽ��� ����
    int D; // Ž���� ����
    int temp = 0; // i ���� �����ϱ� ���� ����

    scanf("%d %d %d", &A, &B, &D); // ������ ���ϴ� ���� �Է¹���

    if (1 > A || A > B || B > 4000000 || B > A + 2000000 || D < 0 || D > 9) // ������ ����
    {
        return 0;
    }

    for (i = A; i <= B; i++) // ���� A���� B���� Ž��
    {
        prime = 1; // �Ҽ� �Ǻ� ������ 1�� �ʱ�ȭ

        if (i < 2) // 2���� ������ �Ҽ��� �ƴϹǷ� continue
        {
            continue;
        }

        for (j = 2; j * j <= i; j++) // �Ҽ� �Ǻ�
        {
            if (i % j == 0) // i���� j�� �������� �� �������� ������� Ȯ��
            {
                prime = 0; // �Ҽ��� �ƴ�
                break;
            }
        }

        if (prime == 1) // �Ҽ��� ���� D�� �����ϴ��� Ȯ��
        {
            temp = i; // i ���� ����
            while (temp != 0)
            {
                if (temp % 10 == D) // �������� ����
                {
                    count++; // D�� �����ϰ� ���� ��� ����
                    break;
                }
                temp /= 10; // ���� �ڸ����� �̵�
            }
        }
    }

    printf("%d", count); // ��� ���

    return 0;
}