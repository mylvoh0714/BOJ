n = int(input())
list = [-10001,]
for _ in range(n):
    val = int(input())
    list.append(val)

list.sort()

ans = 0

i = 1
while(i<=n-1 and list[i+1] < 1):
    ans += list[i]*list[i+1]
    i+=2

j = n
while(j>=2 and list[j-1] > 1):
    ans += list[j]*list[j-1]
    j-=2

for k in range(i,j+1):
    ans += list[k]

print(ans)
