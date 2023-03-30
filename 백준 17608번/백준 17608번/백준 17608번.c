#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 100001 // 최대 범위

int stack[MAX] = { 0 }; // 막대기의 높이 저장 스택
int h[MAX] = { 0 }; // 막대기의 높이
int top = -1; // 스택의 꼭대기

int Full()
{
	if (top >= MAX) // 스택의 인덱스 0부터 시작
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

void push(int data) // 스택이 꽉 차있는지 검사하고, 그렇지 않다면 원소를 스택의 가장 윗부분에 추가
{
	if (!Full())
	{
		top++;
		stack[top] = data;
	}
}

int pop() // 스택이 비어있는지 검사하고, 그렇지 않다면 가장 윗 원소를 반환
{
	if (!Empty())
	{
		return stack[top--];
	}
	return 0;
}

int main(void)
{
	int i = 0; // for문 작동 변수
	int N = 0; // 막대기 개수
	int height = 0; // stack에서 pop을 실행 한 결과 저장
	int count = 1; // 오른쪽에서 보이는 막대기의 개수, 첫 번째 막대기는 보이기 때문에 초기값 1로 설정

	scanf("%d", &N); // 막대기 개수 입력

	if (N < 2 || N > 100000)
	{
		return 0;
	}

	for (i = 0; i < N; i++) // N개의 막대기의 높이를 각각 입력받음
	{
		scanf("%d", &h[i]);

		if (h[i] < 1 || h[i] > 100000)
		{
			return 0;
		}

		push(h[i]); // stack에 저장 (역순)
	}

	i = 1;

	while (1)
	{
		height = pop(); // stack에 저장된 높이 불러옴
		
		if (height > h[N - i]) // 현재 높이보다 다음 높이가 더 클 경우
		{
			count++; // 보이는 막대기 개수 증가
		}

		if (height == 0) // 검사할 스택이 비어있는 경우
		{
			break;
		}
		i++;
	}

	printf("%d", count); // 결과 출력

	return 0;
}