out = "\n"
for tc in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    INITIAL = sum(a)

    if(len(a)%2 == 0):
        a.append(0)
        n += 1

    for i in range(1,n,2):
        if(a[i] <= a[i-1]):
            a[i-1] = a[i]
            a[i+1] = 0
        elif(a[i] > a[i-1] and a[i] < a[i-1] + a[i+1]):
            a[i+1] = a[i]-a[i-1]
    FINAL = sum(a)

    out += f'{INITIAL - FINAL}\n'
print(out)