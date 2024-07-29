# [ 알고리즘 ]
# 왕복 이동 경로를 일직선의 이동 경로로 생각한 후 각 주유소 사이의 거리를 계산
# 주유소 사이의 거리가 200을 초과하는 경우가 있으면 IMPOSSIBLE 출력, 없으면 POSSIBLE 출력

# [ 이동 경로 ]

    # 더슨 크릭 --------- 1422 Miles ---------> 델타 정션
    # ARR -----------------------------------> DES
    # DES <----------------------------------- ARR

# [ 가상 이동 경로 ] - 왕복 이동 경로를 연결해 일직선의 이동 경로로 생각

    # 더슨 크릭 --------- 1422 Miles --------->  델타 정션  --------- 1422 Miles ---------> 더슨 크릭
    # ARR -----------------------------------> DES ARR -----------------------------------> DES

def main():
    """씨부엉 난이도 중 2일차 알고리즘 함수"""

    # 가상 고속도로 길이 설정
    highway_length = 1422 * 2

    while True:

        # 충전소 개수 입력
        charging_station_count = int(input())

        # 충전소의 개수가 0이 입력된 경우 루프 종료
        if charging_station_count == 0: break

        # 충전소 위치 입력
        # 델타 정션 이후의 부분은 대칭이므로 계산 할 이유가 없으니 델타 정션 이후의 첫 충전소까지만 입력
        charging_stations = []
        for i in range(charging_station_count): 
            location = int(input())
            charging_stations.append(location)
        charging_stations.sort()
        charging_stations.append(highway_length - charging_stations[-1])

        # 충전소 사이의 거리가 200을 초과하는 경우가 있으면 결과를 IMPOSSIBLE으로 지정, 없으면 POSSIBLE으로 지정
        arrival_possible = "POSSIBLE"
        for i in range(charging_station_count):
            if charging_stations[i + 1] - charging_stations[i] > 200: 
                arrival_possible = "IMPOSSIBLE"
                break

        # 결과 출력
        print(arrival_possible)

main()