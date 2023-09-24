def up_one_alp(alp, answer):
    alp += 1
    answer += 1
    print("알고력에 1시간 사용 // 총 사용 시간 : ", answer, "현재 알고력 : ", alp)

    return alp, answer

def up_one_cop(cop, answer):
    cop += 1
    answer += 1
    print("코딩력에 1시간 사용 // 총 사용 시간 : ", answer, "현재 코딩력 : ", cop)

    return cop, answer

def up_alp_cop(alp, cop, answer, problems, i):
    print("알고력, 코딩력 모두 증가하는 함수 호출")
    alp += problems[i][2]
    cop += problems[i][3]
    answer += problems[i][4]

    print("변화 후 알고력 : ", alp)
    print("변화 후 코딩력 : ", cop)
    print("소모된 시간 : ", problems[i][4])
    return alp, cop, answer

def scan_problems(alp, cop, problems, alp_max, cop_max, answer):
    # 문제 스캔 후 저장해야 하는 값은?
    # 다음으로 풀 수 있는 최소한의 단계
    for i in range(len(problems)):
        if(alp > problems[i][2] and cop > problems[i][3]):
            possible_alp = problems[i][2]
            possible_cop = problems[i][3]
    
    for i in range(len(problems)):
        if(possible_alp < problems[i][2] or possible_cop < problems[i][3]):
            if(possible_alp < problems[i][2] and possible_cop < problems[i][3]):
                next_problem_num = i
            elif(possible_alp < problems[i][2]):
                next_alp = problems[i][2]
            elif(possible_cop < problems[i][2]):
                next_cop = problems[i][3]
        
        if(alp >= alp_max and cop >= cop_max):
            return answer

    next_alp
    next_cop

# 하나의 행동을 하면 모든 문제를 확인해야 할 것 같음
def solution(alp, cop, problems):

    answer = 0

    alp_temp = problems[0][0]
    cop_temp = problems[0][1]

    alp_max = problems[0][0]
    cop_max = problems[0][1]


    # 문제를 풀기 위한 최소한의 조건 만족
    for i in range(len(problems)):
        if (alp_temp > problems[i][0]):
            alp_temp = problems[i][0]
        elif(alp_max < problems[i][0]):
            alp_max = problems[i][0]
        
        print("알고력 최소 : ", alp_temp)
        print("알고력 최대 : ", alp_max)

    while(1):
        if alp_temp <= alp:
            break
        alp, answer = up_one_alp(alp, answer)


    for i in range(len(problems)):
        if (cop_temp > problems[i][1]):
                cop_temp = problems[i][1]
        elif(cop_max < problems[i][1]):
            cop_max = problems[i][1]

        print("코딩력 최소 : ", cop_temp)
        print("코딩력 최대 : ", cop_max)

    while(1):
        if cop_temp <= cop:
            break
        cop, answer = up_one_cop(cop, answer)

    ###############################################
    for i in range(len(problems)):
        if(problems[i][2] + problems[i][3] < problems[i][4]):
            continue

        if(problems[i])
        alp, cop, answer = up_alp_cop(alp, cop, answer, problems, i)
        alp, answer = up_only_alp(alp, answer)
        cop, answer = up_only_cop(cop, answer)
        
    return answer

    

print(solution(10, 10, [[10, 15, 2, 1, 2], [20, 20, 3, 3, 4]]))

    # for i in range(len(problems)):
        # for k in range (i):
        #     if(alp < problems[k][0] or cop < problems[k][1]):
        # print("i 출력 :", i)
        # if(alp < problems[i][0] or cop < problems[i][1]):
        #     if(alp < problems[i][0]):
        #         answer += 1
        #         alp += 1
        #         print("알고력에 1시간 사용 // 사용 시간 : ", answer, "알고력 : ", alp)
        #     elif(cop < problems[i][1]):
        #         answer += 1
        #         cop += 1
        #         print("코딩력에 1시간 사용 // 사용 시간 : ", answer, "코딩력 : ", cop)

            # if(problems[i][2] != 0):
            #     up_alp_cop(alp, cop, problems[i][2], problems[i][4], answer)
            # print("problems[i][0] 출력 : ", problems[i][0])




# 알고력 : 알고리즘에 대한 지식
# 코딩력 : 코드를 구현하는 능력
# 알고력과 코딩력은 0 이상의 정수

### 예시 ###
# 현재 나의 상태
# 알고력 : 15
# 코딩력 : 10

# A 문제 -> 알고력 10, 코딩력 10 요구
# A 문제 해결 가능

# B 문제 -> 알고력 10, 코딩력 20 요구
# B 문제 해결 불가능

# 풀 수 없는 문제를 해결하기 위해서는 알고력과 코딩력을 높여야 함

### 첫 번째 방법 ###
# 알고력을 높이는 방법 => 알고리즘 공부
# 알고력 1을 높이기 위해 '1 시간'이 필요

# 코딩력을 높이는 방법 => 코딩 공부
# 코딩력 1을 높이기 위해 '1 시간'이 필요

### 두 번째 방법 ###
# 현재 풀 수 있는 문제 중 하나를 풀어 알고력과 코딩력을 높임
# 문제마다 올라가는 알고력과 코딩력이 정해져 있음

### 문제를 푸는 경우 ###
# 문제가 요구하는 시간이 필요
# 같은 문제를 여러 번 푸는 것이 가능

### 변수 설명 ###
# 초기의 알고력 : alp
# 초기의 코딩력 : cop
# problems 배열 => [alp_req, cop_req, alp_rwd, cop_rwd, cost]
# problems 배열 => [문제를 푸는데 필요한 알고력, 문제를 푸는데 필요한 코딩력, 문제를 풀었을 때 증가하는 알고력, 문제를 풀었을 때 증가하는 코딩력, 문제를 푸는데 드는 시간]


### 결론 ###
# 주어진 모든 문제를 풀 수 있는 >>>'알고력과 코딩력을 얻는'<<< 최단시간을 구하기
# 절대 모든 문제를 1번 이상 풀 필요가 없음
