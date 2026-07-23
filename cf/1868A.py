for tc in range(int(input())):
    n,m = map(int,input().split())
    M = [[0 for i in range(m)] for j in range(n)]
    for i in range(min(n,m-1)):
        for j in range(m):
            M[i][j] = (j-i)%m
    for i in range(min(n,m-1),n):
        for j in range(m):
            M[i][j] = M[i-1][j]
    
    ans=0
    if m==1:
        ans = 0
    elif n==1:
        ans = 2
    else:
        num = max(m,n)
        B = [0]*(num+1)
        for j in range(m):
            b = [0]*(num+1)
            for i in range(n):
                b[M[i][j]] += 1
            mex = 0
            for i in range(num+1):
                if b[i]: mex += 1
                else: break
            B[mex] += 1
        
        for i in range(num+1):
            if B[i]: ans += 1
            else: break

    print(ans)
    for v in M: print(*v)