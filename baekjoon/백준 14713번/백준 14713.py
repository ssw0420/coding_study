# import sys
# input_a = int(sys.stdin.readline())
# input_str = sys.stdin.readline().split()

################################################################################
"""
백준 14713번
20203.05.10
"""
from collections import deque
L = 0
N = int(input()) #앵무새의 수 입력
pps789_String = [] # 앵무새들이 말한 문장
for i in range(N):
    pps789_String.append(deque(input().split())) # 앵무새가 말한 문장 공백으로 구분

cseteram_String = deque(input().split()) # cseteram이 받아 적은 문장

if L == 1:
    print("Possible")
elif L == 0:
    print("Impossible")
