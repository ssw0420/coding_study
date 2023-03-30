#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
	int T; // 반복 횟수
	int i, j; // 변수
	int num = 0; // 반복문 사용을 위한 수
	char W[51] = { 0 }; // 문자 저장 공간

	scanf("%d", &T); // 반복 횟수 입력

	for (i = 0; i < T; i++) // T번 반복
	{
		scanf("%s", W); // 문자 입력

		for (j = 0; j < strlen(W); j++) // 널 문자를 제외한 문자열 길이 반환 함수 이용 -> 최대 반복 횟수
		{
			// 문자 -> 작은 따옴표
			// 문자열 -> 큰따옴표
			// 문자 하나를 각각 확인하므로 작은 따옴표 사용

			if (W[j] == '(') // 시작은 '('여야 하므로 ++ 사용
			{
				num++;
			}
			else if (W[j] == ')') // ')'의 개수가 더 많으면 num이 음수가 되도록 함
			{
				num--;
			}

			if (num < 0) // 반복문 종료 (num이 음수인 경우)
			{
				break;
			}

		}

		if (num == 0) // 알맞게 입력한 경우
		{
			printf("YES\n");
		}
		else // ')'로 시작하였거나 '('또는 ')'개수가 더 많은 경우
		{
			printf("NO\n");
		}

		num = 0; // 다음 반복을 위해 num을 0으로 초기화
		
	}
	return 0;
}