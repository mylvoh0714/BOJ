def Check(num):
    temp = -1
    while(num > 0):
        if temp < num % 10:
            temp = num % 10
        else :
            return False
        num //= 10
    return True

n = int(input())
cnt = -1
idx = 0
while(True):
    if Check(idx) == True : cnt += 1
    if cnt == n :
        print(idx)
        break
    idx+=1
