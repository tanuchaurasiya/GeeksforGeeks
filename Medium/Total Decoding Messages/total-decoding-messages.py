#User function Template for python3

class Solution:
	def CountWays(self, s):
		def dfs(i,n):
            nonlocal d
            if i in d:
                return d[i]
            if s[i]=='0':
                return 0 
            res=0
            res=(res+dfs(i+1,n))%(10**9+7)
            if i+1<n and ((s[i]=='1') or (s[i]=='2' and s[i+1] in '0123456')) :
                res=(res+dfs(i+2,n))%(10**9+7) 
            d[i]=res%(10**9+7)
            return res %(10**9+7)
        n=len(s)
        d={n:1}
        return dfs(0,n)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)
if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		str = input()
		ob = Solution()
		ans = ob.CountWays(str)
		print(ans)

# } Driver Code Ends