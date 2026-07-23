def ans(s):
    """
    :type s: str
    :rtype: int
    """
    d = {}
    l = 0
    ml = 0
    for r in range(len(s)):
        if s[r] in d and d[s[r]] + 1 > l:
            l = d[s[r]]+1
        d[s[r]] = r
        if r-l+1 > ml:
            ml = r-l+1
    return ml

n = int(input())
s = list(map(int,input().split()))
print(ans(s))