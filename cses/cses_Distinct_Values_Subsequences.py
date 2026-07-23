n = input()
a = input()

d = {}
ans = 1
MOD = int(1e9+7)
for c in a.split():
    val = int(c)
    if val not in d: d[val] = 1
    else: d[val] += 1
for k in d:
    ans = (ans * (d[k]+1)) % MOD
print(ans-1)