#User function Template for python3

class Solution:
	def closedIslands(self, grid, r, c):
		#Code here
		def dfs(i,j,grid,r,c):
            if i<0 or j<0 or i>=r or j>=c:
                return False 
            if grid[i][j]==0:
                return True 
            grid[i][j]=0
            left=dfs(i,j-1,grid,r,c)
            right=dfs(i,j+1,grid,r,c)
            up=dfs(i-1,j,grid,r,c)
            down=dfs(i+1,j,grid,r,c) 
            if left==True and right==True and up==True and down==True:
                return True 
            return False
        
        res=0
        for i in range(r):
            for j in range(c):
                if grid[i][j]==1:
                    if dfs(i,j,grid,r,c):
                        res+=1 
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3
		
if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        N, M = map(int,input().split())
        matrix = []
        for i in range(N):
            nums = list(map(int,input().split()))
            matrix.append(nums)
        obj = Solution()
        print(obj.closedIslands(matrix, N, M))
# } Driver Code Ends