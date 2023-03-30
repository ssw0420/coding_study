#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int room[15][15] = { 0 }; // 0 ~ 14, 이차원 배열 원소를 참조하기 위한 행 및 열 첨자는 0에서 (행,열크기 -1)까지 유효
	int i, j; // 층, 호 변수
	int num; // 입력받을 호 or 층
	int T; // T번 반복
	int a = 0; // 반복 횟수 변수

	scanf("%d", &T); // T번 반복


	for (j = 0; j <= 14; j++) // 0층 사람의 수
	{
		room[0][j] = j;
	}

	for (i = 1; i <= 14; i++)
	{
		for (j = 1; j <= 14; j++)
		{
			room[i][j] = room[i - 1][j] + room[i][j - 1]; // ex) 203호의 사람 수 = 101호 + 102호 + 103호 = 202호 + 103호
		}
	}

	for (a = 0; a < T; a++)
	{
		scanf("%d %d", &i, &j);
		printf("%d\n", room[i][j]);
	}

	return 0;
}