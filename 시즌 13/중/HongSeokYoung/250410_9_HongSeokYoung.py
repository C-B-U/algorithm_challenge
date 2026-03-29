# 백준 알고리즘 3216번 '다운로드드' https://www.acmicpc.net/problem/3216

import sys
input = sys.stdin.readline

N = int(input())
songs = [tuple(map(int, input().split())) for _ in range(N)]

start_time = 0
remaining_time = 0

for play_time, download_time in songs:
    remaining_time -= download_time
    if remaining_time < 0:
        start_time -= remaining_time
        remaining_time = 0
    remaining_time += play_time

print(start_time)