white = [[0]*100 for i in range(100)] # 100 x 100 크기의 2차원 리스트 생성
# [0] * 100 은 0으로 이루어진 길이가 100인 리스트를 생성하는 표현식
result = 0
for _ in range (int(input())):
    X, Y = map(int, input().split())
    for i in range(10):
        for j in range(10):
            white[X + i][Y + j] = 1

for black in white:
    result += sum(black) # for black in white를 써서 list형으로 접근하였으므로 하나의 행의 숫자들을 모두 더하기 위해 sum 사용

print(result)