out = ""
for tc in range(int(input())):
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    b = [0] + sorted(list(map(int,input().split())))
    s = 0
    S = [1]*(n+1)
    for i in range(len(a)):
        S[i+1] = S[i] + a[i]

    ans = 0
    for i in range(1,len(b)):
        ans += abs(S[b[i]]-S[b[i-1]])
        
    fin = S[-1] - S[b[-1]]
    out += f'{ans+fin}\n'
print(out)