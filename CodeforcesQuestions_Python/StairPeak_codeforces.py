t = int(input())
for i in range(t):
    a, b, c = map(int, input().split())
    if b>a and c>b:
        print("STAIR")
    elif b>a and b>c:
        print("PEAK")
    else:
        print("NONE")
 