out = ""
for tc in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    s = 0
    S = [0]*n
    ans=True
    for i in range(n):
        s += a[i]
        if(s < ((i+1)*(i+2)//2)):
            ans=False
    out += f'{"YES" if ans else "NO"}\n'
print(out)