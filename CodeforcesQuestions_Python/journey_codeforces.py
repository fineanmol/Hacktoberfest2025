t=int(input())
for i in range(t):
    n, a, b, c = map(int, input().split())
    s = a + b + c
    full = n // s
    days = full * 3
    covered = full * s

    if covered >= n:
        print(days)
    elif covered + a >= n:
        print(days + 1)
    elif covered + a + b >= n:
        print(days + 2)
    else:
        print(days + 3)

