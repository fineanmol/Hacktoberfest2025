t = int(input())
for i in range(t):
    
    a, b= map(int, input().split())
    print(min(a,b),end=" ")
    print(max(a,b))

