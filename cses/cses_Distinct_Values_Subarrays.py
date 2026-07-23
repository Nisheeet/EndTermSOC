n = int(input())
a = list(map(int,input().split()))

l = r = 0
d = {}
ans = 0
for r in range(n):
    if a[r] in d: l = max(l,d[a[r]]+1)
    ans += r-l+1
    d[a[r]] = r
print(ans)