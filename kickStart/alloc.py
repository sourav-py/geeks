t = int(input())
for k in range(0,t):
    n,b = map(int,input().split())
    houses = list(map(int,input().split()))
    houses.sort()
    count = 0
    result = 0
    spent = houses[count]
    while(spent <= b):
    
        result += 1
        count += 1
        spent += houses[count]
    print("Case #%d: %d"%(k+1,result))
        
