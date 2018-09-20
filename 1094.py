import sys
read = sys.stdin.readline

n = int(input())
ans = 0
mod = 64
while(n>0):
    if n >= mod:
        n -= mod
        mod //= 2
        ans += 1
    else:
        mod //= 2
print(ans)
