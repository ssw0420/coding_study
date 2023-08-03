K, L = map(int, input().split())
count = 0
for i in range(2, L):
    if K % i == 0:
        print("BAD", i)
        count = 1
        break

if count != 1:
    print("GOOD")