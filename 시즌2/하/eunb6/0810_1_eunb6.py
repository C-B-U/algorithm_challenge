# -*- coding: utf-8 -*-
"""
Created on Wed Aug 10 22:30:34 2022

@author: a0060
"""

list = []
n = int(input())

for _ in range (n):
    list.append(int(input()))
for i in sorted(list):
    print(i)