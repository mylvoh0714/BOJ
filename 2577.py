import sys
read = sys.stdin.readline

a = int(read())
b = int(read())
c = int(read())
num = a*b*c
list = [0,0,0,0,0,0,0,0,0,0] # list[0] : 0이 쓰인 갯수
while(num > 0):
    tar = num%10
    list[tar] += 1
    num //= 10

for i in list:
    print(i)
