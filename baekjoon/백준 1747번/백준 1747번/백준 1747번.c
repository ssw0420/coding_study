#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// C6262오류 발생 -> 배열을 전역변수로 옮기면 해결됨
int prime[1100000] = { 0 }; // 소수 판단 배열
// 어느정도 값이 커지면 1003001이 출력되므로 이를 위해 범위를 크게 잡음

int main(void)
{
	int N; // 숫자 입력
	int i, j; // 소수 판별 for문 변수
	char string[8]; // 1000000까지 이므로 이를 저장하기 위한 배열
	int len = 0; // 문자열의 길이
	int k; // 팰린드롬 판단 for문 변수
	int count = 0; // 조건 판단 변수

	scanf("%d", &N);

	if (N < 1 || N > 1000000)
	{
		return 0;
	}

	prime[0] = prime[1] = 1; // 예외 초기화

	for (i = N; i <= 1100000; i++) // 소수인지 판단 & 어느정도 값이 커지면 1003001이 출력되므로 이를 위해 범위를 크게 잡음
	{
		for (j = 2; j * j <= i; j++) // 소수 판별
		{
			if (i % j == 0) // 나누어 떨어짐
			{
				prime[i] = 1; // 소수가 아님
				break;
			}
		}

		if (prime[i] == 0) // 소수인 경우 작동
		{
			sprintf(string, "%d", i); // 숫자를 문자열로 변환
			len = strlen(string); // 문자열의 길이 파악
			for (k = 0; k < len / 2; k++) // 문자열을 절반 나눠서 판단
			{
				if (string[k] != string[len - k - 1]) // 문자열을 앞과 뒤에서 순서대로 비교
				{
					break;
				}
				else
				{
					count++;
				}
			}

			if (count == len / 2) // 모든 조건에 부합할 경우 for문을 빠져나감
			{
				printf("%d", i);
				break;
			}
			count = 0; // count 변수 초기화
		}
	}

	return 0;
}