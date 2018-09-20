import sys
n = int(input())
dic = {}
for i in range(n):
    name, state = map(str,sys.stdin.readline().split())
    dic[name] = state
list = []
for key, value in dic.items() :
    if value == 'enter' :
        list.append(key)
list.sort(reverse=True)
for i in list:
    print(i)
