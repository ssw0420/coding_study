#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int queue[10001] = { 0 };
int first = 0; // queue가 비어있는 상태
int count = 0;
int rear = 0;

int empty() // queue가 비어있는 지 확인
{
	if (count == 0)
	{
		return 1;
	}
	else if (count != 0)
	{
		return 0;
	}
}

void push(int num) // push x 연산
{
	queue[rear++] = num;
	count++;
}

int pop() // pop 연산
{
	if (empty())
	{
		return -1;
	}
	else if (!empty())
	{
		count--;
		return queue[first++];
	}
}

int size() // size 출력
{
	return count;
}


int front() // queue의 가장 앞에 있는 원소 출력
{
	if (empty())
	{
		return -1;
	}
	else if (!empty())
	{
		return queue[first];
	}
}

int back() // queue의 가장 뒤에 있는 원소 출력
{
	if (empty())
	{
		return -1;
	}
	else if (!empty())
	{
		return queue[rear - 1];
	}
}

int main(void)
{
	int N = 0; // 명령의 수
	int num = 0; // 명령에서 주어지는 정수
	int i = 0; // for문 변수
	char str[6] = { 0 }; // 명령 입력

	scanf("%d", &N);

	if (N < 1 || N > 10000) // 명령의 수 범위 설정
	{
		return 0;
	}

	for (i = 0; i < N; i++)
	{
		scanf("%s", str); // 명령을 입력받음

		if (strcmp(str, "push") == 0) // push x 연산 작동
		{
			scanf("%d", &num);
			push(num);
			if (num < 1 || num > 100000) // 정수 범위 설정
			{
				return 0;
			}
		}
		else if (strcmp(str, "pop") == 0)
		{
			printf("%d\n", pop());
		}
		else if (strcmp(str, "size") == 0)
		{
			printf("%d\n", size());
		}
		else if (strcmp(str, "empty") == 0)
		{
			printf("%d\n", empty());
		}
		else if (strcmp(str, "front") == 0)
		{
			printf("%d\n", front());
		}
		else if (strcmp(str, "back") == 0)
		{
			printf("%d\n", back());
		}
		else
		{
			return 0;
		}
	}

	return 0;
}