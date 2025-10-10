t = int(input())
for i in range(t):
    a, b, c = map(int, input().split())
    minimum=a
    if b<minimum:
        minimum=b
    if c<minimum:
        minimum=c

    maximum=a
    if b>maximum:
        maximum=b
    if c>maximum:
        maximum=c
    
    middle=a+b+c-(minimum+maximum)
    print(middle)
 