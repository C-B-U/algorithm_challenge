color_code={
    "black": [0,1],
    "brown": [1,10],
    "red": [2,100],
    "orange": [3,1000],
    "yellow": [4,10000],
    "green": [5,100000],
    "blue": [6,1000000],
    "violet": [7,10000000],
    "grey": [8,100000000],
    "white": [9,1000000000],
    }


color1=input()
color2=input()
color3=input()

calculate_register_value= (color_code[color1][0]*10+color_code[color2][0])*color_code[color3][1]

print(calculate_register_value)


























