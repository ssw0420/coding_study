#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a, b; // 입력받는 수
	int bg, sl; // 큰 수와 작은 수 구분
	int i; // 변수
	int g, l; // 최대공약수, 최소공배수

	scanf("%d %d", &a, &b);

	if (a > 10000 || b > 10000) // 두 수가 10000초과시 종료
	{
		return 0;
	}

	bg = (a >= b) ? a : b; // 크거나 같은 수 대입
	sl = (a <= b) ? a : b; // 작거나 같은 수 대입



	for (i = 1; i <= sl; i++) // 작은 수보다 적게 반복 (최대공약수)
	{
		if (bg % i == 0 && sl % i == 0)
		{
			g = i;
		}
	}

	for (i = bg; ; i++) // 큰 수부터 반복 시작 (최소공배수)
	{
		if (i % bg == 0 && i % sl == 0)
		{
			l = i;
			break;
		}
	}

	printf("%d\n%d", g, l); // 결과값 출력

	return 0;
}