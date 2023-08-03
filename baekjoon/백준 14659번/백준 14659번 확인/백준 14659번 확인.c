#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1000001
int height[MAX] = { 0 }; // 최대 높이 100000

int main()
{
	int N = 0; // 봉우리의 수 겸 활잡이의 수
	int last = 0; // 최종 처치 수
	int result = 0; // 현재 처치한 수
	int count = 1; // 봉우리 수 체크
	int next = 0; // 다음 봉우리와의 비교

	scanf("%d", &N); // 봉우리의 수 겸 활잡이의 수 입력

	if (N < 1 || N > 30000) // N의 범위 제한
	{
		return 0;
	}

	for (int i = 0; i < N; i++) // N번 반복
	{
		scanf("%d", &height[i]); // 봉우리의 높이 입력
		if (height[i] == height[i - 1])
		{
			return 0;
		}
	}

	for (int i = 0; i < N - 1; i++) // 마지막 활잡이는 처치할 적의 수가 없음
	{
		if (height[i] != 0) // 이전 봉우리보다 더 낮은 높이여서 높이값이 사라지지 않은 경우만 while문이 작동하도록 함
		{
			count = 1; // 바로 다음 번의 봉우리와 비교하기 위해 count 초기화
			while (height[i] > height[i + count]) // count를 증가시켜 가며 봉우리를 이동함
			{
				if (height[i + count] == 0)
				{
					break; // 무한루프 제거
				}
				height[i + count] = 0; // while문 작동 횟수를 줄이기 위해 봉우리 높이 삭제
				result++; // 현재 처치한 수 증가
				count++; // 다음 봉우리로 이동
			}
		}

		if (result > last) // 현재 활잡이가 처치한 적의 수와 지금까지 최고 활잡이가 처치한 수를 비교
		{
			last = result; // 결과 값 출력을 위함
		}
		result = 0; // 현재 처치 수 초기화
	}
	printf("%d", last); // 결과 출력
}

/*
				if (height[i + count] == 0)
				{
					break;
				}

				height[i + count] = 0;
*/