#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
import heapq 
from collections import defaultdict 
class Solution:
    def isStraightHand(self, N, groupSize, hand):
        d=defaultdict(int) 
        for x in hand: 
            d[x]+=1 

        h=hand.copy()
        heapq.heapify(h) 
        while h:
            minn=heapq.heappop(h)
            if d[minn]==0:
                continue
            gs=groupSize 
            while gs:
                if d[minn]==0:
                    return False 
                d[minn]-=1 
                minn+=1
                gs-=1 
        return True
        

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N, groupSize = list(map(int, input().split()))
        hand = list(map(int, input().split()))
        ob = Solution()
        res = ob.isStraightHand(N, groupSize, hand);
        print(res)
# } Driver Code Ends