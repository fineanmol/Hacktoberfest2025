t = int(input())
for i in range(t):
    a, b, c = map(int, input().split())
    if a + b == c:
        print("+")
    elif a - b == c:
        print("-")
 