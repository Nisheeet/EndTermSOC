import math
out = ""
for tc in range(int(input())):
    n,x,y = map(int,input().split())
    p = list(map(int,input().split()))
    g = math.gcd(x,y)
    ch = [abs(i+1 - p[i])%g for i in range(n)]
    ans = True
    for i in range(n):
        ans = ans and (ch[i] == 0)
    out += f'{"YES" if ans else "NO"}\n'
print(out)