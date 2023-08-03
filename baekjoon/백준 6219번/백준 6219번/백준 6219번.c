#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int A, B; // 범위
	int i, j; // 에라토스테네스의 체에 활용할 변수
	int num[4000001] = { 0 }; // 소수 판별 저장 배열
	int count = 0; // 숫자 D를 포함하는 소수의 개수
	int D; // 탐색할 숫자

	scanf("%d %d %d", &A, &B, &D);

	if (1 > A || A > B || B > 4000000 || B > A + 2000000)
	{
		return 0;
	}

	// 소수 판별법은 에라토스테네스의 체 활용 (2960번 문제에서보다 개선시킴)
	for (i = 2; i <= B; i++) // 2부터 i를 증가시킴
	{
		if (num[i] == 0) // 소수가 아닐 경우만 실행
		{
			for (j = i; j <= B; j += i)
			{
				num[j] = 1; // 해당 수가 소수일 경우 배열의 수를 변환
			}
		}
	}

	for (i = A; i <= B; i++) // A부터 B까지의 범위
	{
		if (num[i] == 1) // 소수인 경우에만 실행
		{
			while (i != 0) // i가 0이 아닌 경우
			{
				if (i % 10 == D) // 나머지를 구함
				{
					count++; // D를 포함하고 있을 경우 증가
				}
				i /= 10; // 다음 자릿수로 이동
			}
		}
	}
	printf("%d\n", count);

	return 0;
}