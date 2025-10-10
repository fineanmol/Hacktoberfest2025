t=int(input())

for i in range(t):
    a,b,c=map(int,input().split())
    if((b-(a*i)==c-b)):
        print("YES")
    elif(((b*i)-(a)==c-(b*i))):
        print("YES")
    elif((b-a==(c*i)-b)):    
        print("YES")
    else:
        print("NO")
    

    