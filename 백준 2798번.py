N, M = map(int, input().split())
Card = list(map(int, input().split()))
result = 0
for i in range(N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            temp = Card[i] + Card[j] + Card[k] # 카드 3개의 합
            if temp <= M:
                result = max(result, temp)
                # 둘 중에 더 큰 값을 result에 저장
                # 처음에는 result가 0이므로 temp값이 대입될 것
print(result)