#User function Template for python3

class Solution:

    def CountPS(self, s,n):
        # code here 
        res=0
        n=len(s)
        for i in range(n):
            # for odd length palindrome
            l=i
            r=i 
            while l>=0 and r<n and s[l]==s[r]:
                res+=1
                l-=1
                r+=1 
            
            # for even length palindrome 
            l=i
            r=i+1  
            while l>=0 and r<n and s[l]==s[r]:
                res+=1
                l-=1
                r+=1 
        return res-n
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        N = int(input())
        S = input()

        solObj = Solution()

        print(solObj.CountPS(S,N))
# } Driver Code Ends