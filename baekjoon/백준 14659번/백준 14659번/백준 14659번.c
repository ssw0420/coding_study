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

/*
문제
“반갑다. 내 이름은 반고흐#31555! 조선 최고의 활잡이지. 오늘도 난 금강산 위에서 적들을 노리고 있지. 내 앞에 있는 적들이라면 누구도 놓치지 않아! 좋아, 이제 곧 월식이 시작되는군. 월식이 시작되면 용이 적들을 집어삼킬 것이다. 잘 봐두어라! 마장동 활잡이 반고흐#31555님의 실력을-!”

반고흐#31555는 자기 뒤쪽 봉우리에 덩기#3958이 있음을 전혀 모르고 있었다. 덩기#3958도 반고흐#31555와 마찬가지로 월식이 시작되면 용을 불러내어 눈앞에 있는 다른 활잡이들을 모두 처치할 생각이다. 사실, 반고흐#31555와 덩기#3958 뿐만 아니라 금강 산맥의 N개 봉우리에 있는 모든 활잡이들이 같은 생각을 가지고 있다.

반고흐#31555가 있는 금강 산맥에는 총 N개의 봉우리가 있고, 모든 봉우리마다 한 명의 활잡이가 서서 월식이 시작되기만을 기다리고 있다. 다만, 애석하게도, 천계에 맥도날드가 생겨 용들이 살이 찐 탓에 용들은 자신보다 낮은 봉우리에 서있는 적들만 처치할 수 있게 되었다. 또한 용들은 처음 출발한 봉우리보다 높은 봉우리를 만나면 그대로 공격을 포기하고 금강산자락에 드러누워 낮잠을 청한다고 한다. 봉우리의 높이는 모두 다르고 모든 용들은 오른쪽으로만 나아가며, 중간에 방향을 틀거나, 봉우리가 무너지거나 솟아나는 경우는 없다.

“달에 마구니가 끼었구나.”

드디어 월식이 시작됐다! 과연 이들 활잡이 중 최고의 활잡이는 누구일까? 최고의 활잡이가 최대 몇 명의 적을 처치할 수 있는지 알아보자.

입력
첫째 줄에 봉우리의 수 겸 활잡이의 수 N이 주어진다. (1 ≤ N ≤ 30,000) 둘째 줄에 N개 봉우리의 높이가 왼쪽 봉우리부터 순서대로 주어진다. (1 ≤ 높이 ≤ 100,000) 각각 봉우리의 높이는 중복 없이 유일하다.

출력
최고의 활잡이가 처치할 수 있는 적의 최대 숫자를 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001

int top = -1;
int stack[MAX] = { 0 }; // 봉우리의 높이 저장
int altitude[MAX] = { 0 }; // 봉우리 높이 입력값 저장
int num[MAX] = { 0 }; // 비교를 위한 배열
int sub_result[MAX] = { 0 }; // 결과 임시 저장 배열

int Empty()
{
	if (top == -1) // 스택이 비어있는지 검사
	{
		return 1;
	}
	return 0;
}

int pop() // 스택이 비어있는지 검사하고, 그렇지 않다면 top 감소
{
	if (!Empty())
	{
		return stack[top--];
	}
}

void push(int data) // 원소를 스택의 가장 윗부분에 추가
{
	top++;
	stack[top] = data;
}

int main(void)
{
	int i, j; // for문 작동 변수
	int N; // 봉우리의 수 겸 활잡이의 수 N
	int index = 0; // 비교를 위한 변수
	int result = 0; // 결과 값
	int A = 0; // pop() 활용 변수

	scanf("%d", &N);

	if (N < 1 || N > 30000)
	{
		return 0;
	}

	for (i = 0; i < N; i++)
	{
		scanf("%d", &altitude[i]); // 봉우리 높이 입력

		if (i > 0 && altitude[i] == altitude[i - 1])
		{
			continue;
		}
		push(altitude[i]); // 스택에 봉우리 높이 저장
	}
	
	for (i = 0; i < N;) // 봉우리의 총 개수 만큼 작동
	{
		num[N - i - 1] = pop(); // 스택 활용

		if (num[N - i - 1] > altitude[i]) // 다음 봉우리보다 높은 숫자인 경우
		{
			sub_result[index] = 1;
			index++;
		}
		else
		{
			index = 0;
		}
		i++;
	}

	for (j = 0; j < N; j++)
	{
		if (sub_result[j] == 1)
		{
			result = j; // 결과 값에 저장
		}
	}

	printf("%d", result);

	return 0;
}