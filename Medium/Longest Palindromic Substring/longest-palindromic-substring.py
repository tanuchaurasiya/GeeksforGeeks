#User function Template for python3

class Solution:
    def longestPalindrome(self, s):
        op=-10**9
        oplen=0
        n=len(s)
        for i in range(n):
            # for odd length palindrome
            l=i
            r=i 
            c=s[i]
            while l>=0 and r<n and s[l]==s[r]:
                if l!=r:
                    c=s[l]+c+s[r] 
                l-=1
                r+=1 
            clen=len(c)
            if clen>oplen:
                oplen=clen
                op=c
            
            # for even length palindrome 
            l=i
            r=i+1  
            c=""
            while l>=0 and r<n and s[l]==s[r]:
                c=s[l]+c+s[r]
                l-=1
                r+=1 
            clen=len(c)
            if clen>oplen:
                oplen=clen
                op=c
        # print(op,oplen)
        return op


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        
        S = input().strip()
        ob=Solution()
        print(ob.longestPalindrome(S))
# } Driver Code Ends