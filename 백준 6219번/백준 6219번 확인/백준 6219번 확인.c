#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int A, B; // 범위
    int i; // for문 변수
    int j; // 에라토스테네스의 체에 활용할 변수
    int prime = 1; // 소수 판별 변수
    int count = 0; // 숫자 D를 포함하는 소수의 개수
    int D; // 탐색할 숫자
    int temp = 0; // i 값을 보존하기 위한 변수

    scanf("%d %d %d", &A, &B, &D); // 범위와 원하는 수를 입력받음

    if (1 > A || A > B || B > 4000000 || B > A + 2000000 || D < 0 || D > 9) // 문제의 조건
    {
        return 0;
    }

    for (i = A; i <= B; i++) // 범위 A부터 B까지 탐색
    {
        prime = 1; // 소수 판별 변수를 1로 초기화

        if (i < 2) // 2보다 작으면 소수가 아니므로 continue
        {
            continue;
        }

        for (j = 2; j * j <= i; j++) // 소수 판별
        {
            if (i % j == 0) // i에서 j를 나누었을 떄 나머지가 생기는지 확인
            {
                prime = 0; // 소수가 아님
                break;
            }
        }

        if (prime == 1) // 소수일 때만 D를 포함하는지 확인
        {
            temp = i; // i 값을 보존
            while (temp != 0)
            {
                if (temp % 10 == D) // 나머지를 구함
                {
                    count++; // D를 포함하고 있을 경우 증가
                    break;
                }
                temp /= 10; // 다음 자릿수로 이동
            }
        }
    }

    printf("%d", count); // 결과 출력

    return 0;
}