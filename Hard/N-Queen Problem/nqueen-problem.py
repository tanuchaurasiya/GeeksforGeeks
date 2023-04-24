#User function Template for python3

#User function Template for python3

class Solution:
    def nQueen(self, n):
        def isSafe(row,col,board,n,bottomDia,upperDia,horizontalRow):
            if bottomDia[row+col]==1 or upperDia[n-1+col-row]==1 or horizontalRow[row]==1:
                return 0 
            return 1
        
        def solve(col,board,ds,ans,n,bottomDia,upperDia,horizontalRow):
            if col==n:
                # print(ds)
                ans.append(ds.copy()) 
                ds=[] 
                return 
            for row in range(n):
                if isSafe(row,col,board,n,bottomDia,upperDia,horizontalRow):
                    board[row][col]='Q' 
                    ds.append(row+1)
                    bottomDia[row+col]=1 
                    upperDia[n-1+col-row]=1 
                    horizontalRow[row]=1 
                    solve(col+1,board,ds,ans,n,bottomDia,upperDia,horizontalRow)
                    board[row][col]='.' 
                    ds.pop()
                    bottomDia[row+col]=0
                    upperDia[n-1+col-row]=0 
                    horizontalRow[row]=0
        ans=[]
        board=[] 
        N=2*n-1
        bottomDia=[0]*N
        upperDia=[0]*N
        horizontalRow=[0]*N 
        ds=[]
        for i in range(n):
            s=["."]*n
            board.append(s) 
        solve(0,board,ds,ans,n,bottomDia,upperDia,horizontalRow)
        return ans 



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        
        ob = Solution()
        ans = ob.nQueen(n)
        if(len(ans) == 0):
            print("-1")
        else:
            for i in range(len(ans)):
                print("[",end="")
                for j in range(len(ans[i])):
                    print(ans[i][j],end = " ")
                print("]",end = " ")
            print()
                
# } Driver Code Ends