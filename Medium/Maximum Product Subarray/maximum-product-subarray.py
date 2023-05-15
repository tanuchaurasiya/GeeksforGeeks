#User function Template for python3
#User function Template for python3
class Solution:

    # Function to find maximum
    # product subarray
    def maxProduct(self,nums, n):
        # code here
        res=-10**9
        prefix=1
        suffix=1
        for i in range(n):
            if prefix==0:
                prefix=1
            if suffix==0:
                suffix=1
            prefix=prefix*nums[i] 
            suffix=suffix*nums[n-i-1]
            res=max(res,max(prefix,suffix))
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.maxProduct(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends