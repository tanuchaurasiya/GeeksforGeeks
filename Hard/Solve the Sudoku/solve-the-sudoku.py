#User function Template for python3

class Solution: 
    def isValid(self,temp,board,row,col):
            for i in range(9):
                if board[i][col]==temp:
                    return False 
                if board[row][i]==temp:
                    return False 
                if board[3*(row//3)+(i//3)][3*(col//3)+(i%3)]==temp:
                    return False 
            return True 
    def solve(self,board):
        for i in range(9):
            for j in range(9):
                if board[i][j]==0:
                    for temp in [1,2,3,4,5,6,7,8,9] :
                        if self.isValid(temp,board,i,j):
                            board[i][j]=temp 
                            # print(board)
                            if(self.solve(board)==True):
                                return True 
                            else:
                                board[i][j]=0
                    return False
        return True 
    

    def SolveSudoku(self,grid):
        if self.solve(grid) :
            return 1
        return 0
        
    def printGrid(self,arr): 
        for i in range(9):
                for j in range(9):
                    print(arr[i][j],end=" ")
                
        

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t = int(input())
    while(t>0):
        grid = [[0 for i in range(9)] for j in range(9)]
        row = [int(x) for x in input().strip().split()]
        k = 0
        for i in range(9):
            for j in range(9):
                grid[i][j] = row[k]
                k+=1
                
        ob = Solution()
            
        if(ob.SolveSudoku(grid)==True):
            ob.printGrid(grid)
            print()
        else:
            print("No solution exists")
        t = t-1
# } Driver Code Ends