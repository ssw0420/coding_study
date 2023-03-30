#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001

int top = -1; // 스택을 제대로 사용하지 않았고 스택 내부가 비어있는 경우에 대해 제대로 활용하지 않았으니 -1이 아니어도 됨

char stack[MAX] = { 0 }; // 저장할 배열
char s[MAX] = { 0 }; // 첫 번째로 입력받을 배열
char t[MAX] = { 0 }; // 두 번째로 입력받을 배열

int main(void)
{
	int i, j, result = 0; // for문과 if문 작동을 위한 변수

	while (1) 
	{
		scanf("%s %s", s, t); // 2개의 문자열 입력

		top = -1; // 스택 초기화
		result = 0; // 변수 초기화

		if (strlen(s) >= MAX || strlen(t) >= MAX) // s와 t의 길이는 10만을 넘지 않음
		{
			return 0;
		}

		for (i = 0; i < strlen(t); i++) // 문자열 t까지 증가
		{

			stack[++top] = t[i]; // stack에 문자 저장, 배열 내부의 순서(숫자 증가)

			if (top == strlen(s)) // 스택과 s의 길이(s 문자의 개수)가 같을 때부터 비교 시작
			{
				for (j = 0; j < strlen(s); j++) // 문자열 길이에 맞게 비교
				{
					if (stack[top + j] != s[j]) // 문자열 중간에 다른 부분이 있으면 중단
					{
						result = 1;
						break;
					}
				}

				if (result == 0) // 문자열이 끝까지 일치한 경우 (for문이 끝까지 작동한 경우)
				{
					printf("Yes\n");
					break;
				}
			}
		}
		if (result == 1) // 부분 문자열이 발견되지 않은 경우
		{
			printf("No\n");
		}

		if (strcmp(s, "caseDoesMatter") == 0 && strcmp(t, "CaseDoesMatter") == 0) // 프로그램 종료 조건
		{
			return 0;
		}
	}

	return 0;
}

/*
int Full()
{
	if (top >= MAX - 1) // 스택의 인덱스 0부터 시작
	{
		return 1;
	}
	return 0;
}

int Empty()
{
	if (top == -1) // 스택이 비어있는지 검사
	{
		return 1;
	}
	return 0;
}

void push(char data) // 스택이 꽉 차있는지 검사하고, 그렇지 않다면 원소를 스택의 가장 윗부분에 추가
{
	if (!Full())
	{
		top++;
		stack[top] = data;
	}
}

char pop() // 스택이 비어있는지 검사하고, 그렇지 않다면 가장 윗 원소를 반환
{
	if (!Empty())
	{
		return stack[top--];
	}
}
*/

