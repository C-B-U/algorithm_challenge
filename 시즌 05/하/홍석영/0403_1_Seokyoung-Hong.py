resistance_colour_list = ['black','brown','red','orange','yellow','green','blue','violet','grey','white']

col_1 = input()
col_2 = input()
col_3 = input()

value = int(str(resistance_colour_list.index(col_1))+str(resistance_colour_list.index(col_2)))
print(value * (10**resistance_colour_list.index(col_3)))
