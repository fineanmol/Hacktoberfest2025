t=int(input())
for i in range(t):
    a,b,c=map(int,input().split())
    if(a==b+c):
        print("yes")
    elif(b==a+c):
        print("yes")
    elif(c==b+a):
        print("yes")
    else:
        print("no")