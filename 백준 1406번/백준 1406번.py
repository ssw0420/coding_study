# import sys
# input_a = int(sys.stdin.readline())
# input_str = sys.stdin.readline().split()

################################################################################
"""
백준 1406번
20203.05.09
"""
import sys

# 배열 하나로 문제를 풀면 시간초과가 발생하므로 2개의 배열 사용
string_L = list(sys.stdin.readline().rstrip()) # 문자열 입력 => pop 사용을 위해 개행 삭제
string_R = [] # 빈 배열 생성
M = int(sys.stdin.readline()) # 입력할 명령어의 개수

for _ in range(M) : # 입력할 명령어의 개수만큼 for문 작동
    alpha = sys.stdin.readline().split() # 공백으로 문자를 구별 (P 입력 때 공백으로 구분)
    
    if alpha[0] == 'L' and string_L: # L일 때 커서를 좌측으로 1칸 이동
        string_R.append(string_L.pop()) # 좌측 배열을 pop한 후 우측 배열에 추가
    elif alpha[0] == 'D' and string_R: # D일 때 커서를 우측으로 1칸 이동
        string_L.append(string_R.pop()) # 우측 배열을 pop한 후 좌측 배열에 추가
    elif alpha[0] == 'B' and string_L: # 커서 좌촉의 문자 삭제
        string_L.pop() # 좌축 배열의 문자 하나 삭제
    elif alpha[0] == 'P': # P일 때 좌측에 문자 추가
        string_L.append(alpha[1]) # 좌측 배열에 문자 추가

sys.stdout.write(''.join(string_L + list(reversed(string_R)))) # 좌측 배열 바로 뒤에 역순으로 만든 우측 배열의 문자를 이어서 출력