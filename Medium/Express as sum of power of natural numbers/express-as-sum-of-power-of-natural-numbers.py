#User function Template for python3
#User function Template for python
class Solution:
    def numOfWays(self, n, x):
        def help(i,summ):
          #  print(i,summ)
            nonlocal n,x,sq,dp,arr
            if summ>=n or i>sq:
                if summ==n:
                    return 1
                return 0 
            if dp[i][summ]!=-1:
                return dp[i][summ]
            dp[i][summ]=help(i+1,summ+arr[i])%1000000007 + help(i+1,summ)%1000000007
            return dp[i][summ]%1000000007
        sq=int(pow(n,1/x))
        arr=[] 
        for i in range(sq+1):
            arr.append(pow(i,x))
        dp=[] 
        for i in range(sq+1):
            dp.append([-1]*(n+1))
        return help(1,0)
           





#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n,x = input().split()
		n=int(n)
		x=int(x)
		ob = Solution();
		print(ob.numOfWays(n, x))

# } Driver Code Ends