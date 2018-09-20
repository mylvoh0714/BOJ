input();
list = list(map(int,input().split()))
list.sort()
sum = 0
ans = 0
for i in list:
    sum += i
    ans += sum
print(ans)
