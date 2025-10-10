t = int(input())
for _ in range(t):
    n = int(input())
    r = n % 2020
    q = n // 2020
    if r <= q:
        print("YES")
    else:
        print("NO")
