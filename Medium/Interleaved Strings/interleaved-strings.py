#User function Template for python3

 #Your task is to complete this Function \

class Solution:
    #function should return True/False
    def isInterleave(self, s1,s2,s3):
        memo = {}
        
        def dfs(i,j,k):
            if i == len(s2):
                return s1[j:] == s3[k:]
            if j == len(s1):
                return s2[i:] == s3[k:]
            
            ans = False
            if (i,j) in memo:
                return memo[(i,j)]
            else:
                ans = (s2[i] == s3[k] and dfs(i + 1,j,k + 1)) or \
                        (s1[j] == s3[k] and dfs(i,j + 1,k + 1))
                memo[(i,j)] = ans
            
            return memo[(i,j)]
        
        if len(s1) + len(s2) != len(s3):
            return False
        else:
            return dfs(0,0,0)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        arr=input().strip().split()
        if Solution().isInterleave(arr[0], arr[1], arr[2]):
            print(1)
        else:
            print(0)
# contributed By: Harshit Sidhwa
# } Driver Code Ends