"""
    PROBLEM OF GOOGLE KICK START 2019 ROUND A PROBLEM 1 OF 3
    SUBMITTED SUCCESSFULLY
"""

t = int(input())
for k in range(0,t):
    n,p = map(int,input().split())
    players = list(map(int,input().split()))
    players.sort(reverse = True)

    result = []
    trainingTime = 0
    
    curr = 0
    curr_max = 0
    
    while(curr <= n-1): 
        if curr >= p: 
            result.append(trainingTime)
            diff = players[curr_max] - players[curr_max+1]
            trainingTime -= diff*(p-1) 
            curr_max = curr_max+1

        trainingTime += (players[curr_max]-players[curr])
        curr += 1
        if curr == n :
            result.append(trainingTime)
      
        
        
    print("Case #%d: %d"%(k+1,min(result)))
