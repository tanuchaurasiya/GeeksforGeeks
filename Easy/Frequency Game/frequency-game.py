#User function Template for python3


#User function Template for python3

from collections import defaultdict
def LargButMinFreq(arr,n):
    #code here
    minf=10**9
    ele=-10**9
    d=defaultdict(int)
    for x in arr:
        d[x]+=1
    for x in arr:
        if d[x]<=minf:
            if d[x]<minf:
                minf=d[x]
                ele=x 
            else:
                if ele<x:
                    ele=x
    return ele

#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
#Iterating over test cases
for _ in range(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    print(LargButMinFreq(arr, n))
# } Driver Code Ends