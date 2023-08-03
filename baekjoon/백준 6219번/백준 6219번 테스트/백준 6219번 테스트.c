#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int A, B; // 범위
	int i, j; // 에라토스테네스의 체에 활용할 변수
	int k; // for문 변수
	int prime = 0; // 소수 판별 변수
	int count = 0; // 숫자 D를 포함하는 소수의 개수
	int D; // 탐색할 숫자

	scanf("%d %d %d", &A, &B, &D);

	if (1 > A || A > B || B > 4000000 || B > A + 2000000 || D < 0 || D > 9)
	{
		return 0;
	}

	for (k = 2; k <= B; k++) // 2부터 k를 증가시킴
	{
		for (j = k; j <= B; j += k)
		{
			i = j;
			if (i >= A && i <= B) // 범위 A부터 B까지
			{
				while (i != 0)
				{
					if (i % 10 == D) // 나머지를 구함
					{
						count++; // D를 포함하고 있을 경우 증가
						break;
					}
					i /= 10; // 다음 자릿수로 이동
				}
			}
		}
	}

	printf("%d", count);

	return 0;
}