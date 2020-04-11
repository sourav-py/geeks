array = [-2,1,-3,4,-1,2,1,-5,4]
maxElementIndex = array.index(max(array))

start = maxElementIndex
end = maxElementIndex

if maxElementIndex == 0:
    while(sum(array[end+1:])>0):
        end = end+1
elif maxElementIndex==n-1:
    while(sum(array[:start])>0):
        start = start -1
        


