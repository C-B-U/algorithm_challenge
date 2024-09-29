# B가 일반 과목 총점이 아니라 전공 합친 점수였구나.. 왜 안풀리나 했다

N, majors, total = map(int, input().split())
remain_semester = 8 - N

for _ in range(remain_semester):
    major, non_major = map(int, input().split())

    for _ in range(6):
        
        if major: 
            majors += 3
            total += 3
            major -= 1
            
        elif non_major:
            total += 3
            non_major -= 1

if total >= 130 and majors >= 66:
    print("Nice")
else:
    print("Nae ga wae")
