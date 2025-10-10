t=int(input())

for i in range(t):
    a, b, c = map(int, input().split())

    t1 = abs(a - 1)
    t2 = abs(b - c) + abs(c - 1)

    if t1 < t2:
         print(1)
    elif t2 < t1:
        print(2)
    else:
        print(3)
    