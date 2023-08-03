// 에라토스테네스의 체 알고리즘

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N, K; // 입력받을 두 수
	int num[1001] = { 0 }; // 배열을 이용하여 1000까지 확인
	int i, j; // 변수
	int count = 0; // 지워진 숫자의 순서

	scanf("%d %d", &N, &K);

	if (K > N && N > 1000)
	{
		return 0;
	}

	for (i = 2; i <= N; i++) // 2부터 i를 증가시킴
	{
		for (j = i; j <= N; j += i) // i의 배수에 해당하는 수를 확인
		{
			if (num[j] == 0) // 소수가 아닐경우만 실행
			{
				num[j] = 1; // 소수일 경우 배열의 수를 변환
				count++; // 몇 번째로 지워진 숫자인지 확인

				if (count == K) // 지워진 수의 위치와 일치한 경우
				{
					printf("%d\n", j);
					return 0;
				}
			}
		}
	}

	return 0;
}