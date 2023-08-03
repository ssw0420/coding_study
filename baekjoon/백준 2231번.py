N = int(input()) #  자연수 N 입력
for i in range(1, N+1): # 1부터 증가하면서 확인
    num = list(map(int, str(i))) # 각 자리별로 숫자를 나눔
    if N == sum(num) + i: # 주어진 숫자와 각 자리를 더했을 때 N이 되는 경우
        M = i # 생성자 M
        break
    if i == N:
        M = 0
        break
print(M)