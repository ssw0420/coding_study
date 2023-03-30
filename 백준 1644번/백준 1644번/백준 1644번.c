// 소수의 연속합

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int prime[4000001] = { 0 };

int main(void)
{
	int N; // 입력받을 수
	int i, j; // for문 사용 변수
	int sum = 0; // 합을 구하기 위한 변수
	int count = 0; // 경우의 수

	scanf("%d", &N);

	if (1 > N || N > 4000000)
	{
		return 0;
	}

	prime[0] = prime[1] = 1; // 예외처리

	// 소수 탐색
	for (i = 2; i * i <= N; i++) // 2부터 i를 증가시킴
	{
		if (prime[i] == 1) // 소수이면 다음 숫자로 진행
		{
			continue;
		}
		for (j = i * i; j <= N; j += i) // 소수의 배수는 소수가 아님 -> prime[]배열 안의 숫자 변환
		{
			prime[j] = 1; // 소수가 아닐 경우 배열의 수를 변환
		}
	}


	// 소수 합 구하기
	for (i = 2; i <= N; i++) // i가 N이 될 때까지 반복
	{
		if (prime[i] == 0) // 소수인 경우
		{
			sum = i; // 합을 저장하는 변수에 i값 저장
			for (j = i + 1; j <= N; j++) // 다음 수부터 늘려가며 반복
			{
				if (prime[j] == 0) // 소수인 경우
				{
					sum += j; // sum + j 

					if (sum == N) // 합이 N 인경우
					{
						count++; // 경우의 수 증가
						break;
					}
					else if (sum > N) // 합이 N을 초과하는 경우
					{
						break;
					}
				}
			}
		}
	}

	if (prime[N] == 0) // i가 N이며 소수인 경우
	{
		count++; // 경우의 수 증가
	}
	printf("%d", count);

	return 0;
}