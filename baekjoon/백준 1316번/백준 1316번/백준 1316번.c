#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
	int T; // 반복 횟수
	char W[101] = { 0 };
	int i, j, k; // 반복문 사용, j는 기준 문자, k는 비교 문자
	int gp = 0; // 그룹 단어 확인
	int num = 0; // 그룹 단어 개수

	scanf("%d", &T); // 확인할 단어의 총 개수 입력

	for (i = 0; i < T; i++)
	{
		scanf("%s", W); // 단어 입력
		gp = 0; // 그룹 단어 확인용 숫자 초기화

		for (j = 2; j < strlen(W); j++) // 그룹 단어가 아니기 위해서는 최소 3개의 문자가 되어야함, 입력된 단어의 문자만큼 for문 반복
		{
			for (k = 0; k < j - 1; k++) // 그룹 단어 확인
			{
				if (W[j] == W[k] && W[k + 1] != W[j]) // 그룹 단어가 아닌 경우 (같은 단어가 사용되었지만, 연속되지는 않음)
				{
					gp++; // 그룹 단어 확인용 수를 증가시킴
					break;
				}
			}

			if (gp == 1) // 그룹 단어가 아닌 것이 확인되었으므로 다음 단어를 확인하기 위해 for문을 빠져나감
			{
				break;
			}
		}

		if (gp == 0) // 확인한 단어가 그룹 단어인 경우
		{
			num++; // 그룹 단어 개수 증가
		}
	}

	printf("%d", num);

	return 0;
}