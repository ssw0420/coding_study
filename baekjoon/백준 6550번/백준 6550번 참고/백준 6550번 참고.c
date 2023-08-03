#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[100000]; // 첫 번째 입력 배열
char t[100000]; // 두 번째 입력 배열


int main(void)
{
    while (1)
    {
        int count = 0;
        int i;

        scanf("%s %s", s, t); // 문자열 2개 입력

        if (strlen(s) >= 1000000 || strlen(t) >= 1000000) // s와 t의 길이는 10만을 넘지 않음
        {
            return 0;
        }

        for (i = 0; i < strlen(t); i++) // 문자열의 길이동안 비교
        {
            if (t[i] == s[count]) // 비교한 문자열이 같은 경우
            {
                count++;
            }
        }
        if (count != strlen(s)) // 문자열의 길이와 비교된 횟수가 다른 경우
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }

        if (strcmp(s, "caseDoesMatter") == 0 && strcmp(t, "CaseDoesMatter") == 0) // 프로그램 종료 조건
        {
            return 0;
        }
    }
    return 0;
}