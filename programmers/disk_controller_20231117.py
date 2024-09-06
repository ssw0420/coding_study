def solution(jobs):
    jobs.sort(key=lambda x:x[1])

    time=0
    task_time=0
    job_len = len(jobs)
    
    while len(jobs) > 0:
        for job in jobs:
            if job[0] <= time:
                time += job[1] -1
                task_time += time - job[0] + 1
                jobs.remove(job)
                break
        time += 1

    return task_time//job_len

value = [[2, 6],[0, 3], [1, 9]]
value2 = [[0, 3], [1, 9], [2, 6]]
print(solution(value))

# A B C 시점 확인
# A B C 소요 시간 확인
# 순서별 평균 시간 확인 => 최소 힙으로 구현
# 요청부터 종료까지 걸린 평균의 시간이 가장 작을 때의 시간 반환 ( int 형 )