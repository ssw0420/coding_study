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

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001

int top = -1; // stack이 비어있는 경우

char stack[MAX] = { 0 }; // 저장할 배열
char s[MAX] = { 0 }; // 첫 번째로 입력받을 배열
char t[MAX] = { 0 }; // 두 번째로 입력받을 배열

int Empty()
{
	if (top == -1) // 스택이 비어있는지 검사
	{
		return 1;
	}
	return 0;
}

void pop() // 스택이 비어있는지 검사하고, 그렇지 않다면 top 감소
{
	if (!Empty())
	{
		top--;
		return;
	}
}

void push(char data) // 원소를 스택의 가장 윗부분에 추가
{
		top++;
		stack[top] = data;
}

int main(void)
{
	int index = 0;
	int i;

	while (scanf("%s %s", s, t) != EOF) // 문자열 입력
	{
		top = -1; // 초기화
		index = 0;

		for (i = 0; i < strlen(s); i++)
		{
			push(s[i]); // s에 입력받은 모든 문자를 stack에 저장
		}

		for (i = 0; i <= strlen(t); i++) // 문자열 길이 t까지 반복
		{
			if (stack[index] == t[i])
			{
				pop();
				index++;
			}
		}
		if (Empty() == 1) // 부분 문자열에 해당하는 경우
		{
			printf("Yes\n");
		}
		else // 그렇지 않은 경우
		{
			printf("No\n");
		}
	}
	return 0;
}

/*
		if (strcmp(s, "caseDoesMatter") == 0 && strcmp(t, "CaseDoesMatter") == 0) // 프로그램 종료 조건
		{
			return 0;
		}
*/