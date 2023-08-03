#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int i, j, k; // 소수를 찾기 위한 변수
	int num; // i와 j를 곱한 값을 저장할 변수
	int M, N; // 입력받을 수
	int sum = 0, min = 0; // 합, 최솟값
	int all[10001] = { 0 }; // 1~10000 수를 검사하기 위한 배열

	scanf("%d %d", &M, &N);

	if (M > 10000 || N > 10000)
	{
		return 0;
	}

	all[0] = 1, all[1] = 1; // 0과 1은 따로 구분해둠

	for (i = 2; i <= N; i++) // N까지 for문 반복
	{
		for (num = 2, j = i; num <= N; j++) // 배열의 숫자 num이 2부터 N까지 커질 수 있게 설정
		{
			num = i * j; // num에 i와 점점 커지는 변수j를 곱한 수를 저장
			
			if (num >= M && num <= N)
			{
					all[num] = 1; // 배열에 1을 저장함 => 소수
			}
		}
	}

	for (k = M; k < N + 1; k++) // M부터 N까지의 소수를 탐색
	{
		if (all[k] == 0)
		{
			sum += k; // 소수의 합을 구함

			if (min == 0) // 범위 안에 들어왔을 때 if문이 작동하도록 설정
			{
				min = k; // min에 k값을 부여
			}
		}
	}

	if (sum == 0) // 소수가 없을 경우
	{
		printf("-1");
	}
	else // 소수가 있을 경우
	{
		printf("%d\n%d\n", sum, min);
	}

	return 0;
}