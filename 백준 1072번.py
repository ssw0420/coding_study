X, Y = map(int, input().split())
Z = (Y * 100) // X
if Z>=99:
    print(-1)
    exit()
else:
    first = 0
    last = X

    while first != last:
        mid = (first + last) // 2
        # 원래 확률이 Z인데 계산 후 확률이 변한다는 것은 더 적은 판수가 있으면 된다는 뜻
        # 이로 인해 mid 값을 last에 대입시켜서 더 적은 판수를 구하게 함
        if(Y + mid) * 100 // (X + mid) != Z:
            last = mid
        # 원래 확률이 Z인데 계산 후 확률이 변하지 않는다는 것은 더 많은 판수가 있으면 된다는 뜻
        # 이로 인해 mid+1값을 first에 대입시켜서 더 적은 판수를 구하게 함
        else:
            first = mid + 1
result = (first + last) // 2
print(result)