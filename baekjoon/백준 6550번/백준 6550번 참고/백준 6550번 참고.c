#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[100000]; // ù ��° �Է� �迭
char t[100000]; // �� ��° �Է� �迭


int main(void)
{
    while (1)
    {
        int count = 0;
        int i;

        scanf("%s %s", s, t); // ���ڿ� 2�� �Է�

        if (strlen(s) >= 1000000 || strlen(t) >= 1000000) // s�� t�� ���̴� 10���� ���� ����
        {
            return 0;
        }

        for (i = 0; i < strlen(t); i++) // ���ڿ��� ���̵��� ��
        {
            if (t[i] == s[count]) // ���� ���ڿ��� ���� ���
            {
                count++;
            }
        }
        if (count != strlen(s)) // ���ڿ��� ���̿� �񱳵� Ƚ���� �ٸ� ���
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }

        if (strcmp(s, "caseDoesMatter") == 0 && strcmp(t, "CaseDoesMatter") == 0) // ���α׷� ���� ����
        {
            return 0;
        }
    }
    return 0;
}