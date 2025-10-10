t = int(input())
for i in range(t):
    count=0
    a, b, c, d= map(int, input().split())
    if b>a:
        count=count+1
    if c>a:
        count+=1
    if d>a:
        count+=1
    print(count)

