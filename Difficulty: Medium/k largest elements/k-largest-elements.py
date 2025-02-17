
import heapq as hp
class Solution:

    def kLargest(self,arr, k): 
        n=len(arr)
        for i in range(n):
            arr[i]=-arr[i]
        hp.heapify(arr) 
        res=[] 
        for i in range(k):
            res.append(-hp.heappop(arr) )
        
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        ans = ob.kLargest(arr, k)

        print(" ".join(map(str, ans)))
        tc -= 1
        print("~")

# } Driver Code Ends