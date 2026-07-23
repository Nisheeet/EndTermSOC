for tc in range(int(input())):
    n = int(input())
    l = input().split('*')
    ans = 0
    for i in l:
        ans = max(ans,(len(i)+1)//2)
    print(ans)