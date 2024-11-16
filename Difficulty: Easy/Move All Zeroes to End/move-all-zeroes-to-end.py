#User function Template for python3

class Solution:
	def pushZerosToEnd(self,nums):
    	zero=nums.count(0) 
    	n=len(nums)
        j=0
        for i in range(n):
            if nums[i]!=0:
                nums[j]=nums[i]
                j+=1 
        # print(nums)
        for i in range(zero):
            nums[i+j]=0 
        # print(nums)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ob.pushZerosToEnd(arr)
        for x in arr:
            print(x, end=" ")
        print()
        tc -= 1
# } Driver Code Ends