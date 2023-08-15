# arr = [[0, 0, 0], [1, 0, 0], [0, 1, 1]]
# # print(arr[::-1])
# # print(zip(arr))
# # for k in zip(arr):
# #     print("k : ", k)
# # print(*arr)
# # print(zip(arr[::-1]))
# temp = zip(*arr[::-1])
# # print(list(zip(*arr)))
# # for i in zip(*arr):
# #     print("i : ", i)
# # print(temp)
# for i in temp:
#     print("temp:", i)
# # print(list(zip(*arr[::-1])))
# # print(arr[::-1])
# # print(*arr[::-1])
# # temp = zip(*arr[::-1])
# # print(temp)
# # temp2 = map(list, zip(*arr[::-1]))
# # print(temp2)
# # for i in temp2:
# #     print("temp2:", i)
# # print(map(list, zip(*arr[::-1])))
# # print(list(map(list, zip(*arr[::-1]))))

def rotation(key):
    temp = list(map(list, list(zip(*key))))
    return [i[::-1] for i in temp]

def checkin(key, lock):
    M = len(key)
    N = len(lock)
    for i in range(N - M + 1):
        for j in range(N - M + 1):
            a = 0
            for l1 in range(N):
                for l2 in range(N):
                    if ((l1 >= i) & (l1 <= i + M - 1)) & ((l2 >= j) & (l2 <= j + M - 1)):
                        if lock[l1][l2] + key[l1 - i][l2 - j] != 1:
                            a = 1
                            break
                    else:
                        if lock[l1][l2] != 1:
                            a = 1
                            break
                if a == 1:
                    break
            if a == 0:
                return True
    return False

def checkout(key, lock):
    M = len(key)
    N = len(lock)
    for i in range(N):
        for j in range(N):
            if (i < M - 1) | (j < M - 1):
                a = 0
                for l1 in range(N):
                    for l2 in range(N):
                        if ((l1 <= i) & (l1 >= i - M + 1)) & ((l2 <= j) & (l2 >= j - M + 1)):
                            if lock[l1][l2] + key[M - 1 - i + l1][M - 1 - j + l2] != 1:
                                a = 1
                                break
                        else:
                            if lock[l1][l2] != 1:
                                a = 1
                                break
                    if a == 1:
                        break
                if a == 0:
                    return True
    return False


def solution(key, lock):
    for i in range(4):
        if checkin(key, lock):
            return True
        key = rotation(key)
    for i in range(4):
        for j in range(4):
            if checkout(key, lock):
                return True
            key = rotation(key)
        lock = rotation(lock)
    return False
