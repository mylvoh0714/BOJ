#include <cstdio>
#include <cstring>
char a[10002];
char b[10002];
char c[10003]; // c = a+b

int main()
{
    scanf("%s %s", a,b);
    int aIdx = strlen(a)-1;
    int bIdx = strlen(b)-1;
    int cIdx = 10001; // 마지막 index인 10002 = null

    int adder = 0;
    while(aIdx >= 0 || bIdx >= 0 || adder > 0)
    {
        if(aIdx >= 0) adder += a[aIdx--] - '0';
        if(bIdx >= 0) adder += b[bIdx--] - '0';
        c[cIdx--] = adder%10 + '0';
        adder /= 10;
    }
    printf("%s\n",c+cIdx+1);
}
