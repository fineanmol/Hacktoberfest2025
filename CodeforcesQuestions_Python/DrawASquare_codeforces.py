t=int(input())
for i in range(t):
    l,r,d,u=map(int,input().split())
    if l==r and r==d and d==u and u==l:
        print("YES")
    else:
        print("NO")
    

    