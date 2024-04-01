# [ 알고리즘 ]
# 왕복 이동 경로를 일직선의 이동 경로로 생각한 후 각 주유소 사이의 거리를 계산
# 주유소 사이의 거리가 200 이상인 경우가 있으면 IMPOSSIBLE 출력, 없으면 POSSIBLE 출력

# [ 이동 경로 ]

    # 더슨 크릭 --------- 1422 Miles ---------> 델타 정션
    # ARR -----------------------------------> DES
    # ARR <----------------------------------- DES

# [ 가상 이동 경로 ] - 왕복 이동 경로를 연결해 일직선의 이동 경로로 생각

    # 더슨 크릭 --------- 1422 Miles --------->  델타 정션  --------- 1422 Miles ---------> 더슨 크릭
    # ARR -----------------------------------> DES ARR -----------------------------------> DES

highway_length = 1422 * 2
while True:
    charging_station_count = int(input())
    if charging_station_count == 0: break

    charging_stations = []
    for i in range(charging_station_count): 
        location = int(input())
        charging_stations.append(location)
        charging_stations.append(highway_length - location)
    charging_stations.sort()

    arrival_possible = "POSSIBLE"
    location = 0
    for station in charging_stations:
        if station - location > 200: 
            arrival_possible = "IMPOSSIBLE"
            break
        else: location = station

    print(arrival_possible)