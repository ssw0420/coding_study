p=input()
num=['ABC','DEF','GHI','JKL','MNO','PQRS','TUV', 'WXYZ']
result = 0

for char in p:
    for group in num:
        if char in group:
            result += num.index(group) + 3

print(result)
        
# sec=0

# for i in range(len(p)):
#     for j in num:
#         if p[i] in j:
#             sec += num.index(j)+3

# print(sec)