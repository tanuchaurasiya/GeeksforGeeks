
class Solution:
    def isWordExist(self, board, word):
        def isValid(i,j,m,n,visited,board):
            # print(i,j,m,n)
            if i<0 or j<0 or i>=m or j>=n or visited[i][j]==1:
                return 0
            return 1
        def help(m,n,i,j,idx,word,wlen,board,visited):
            if idx==wlen:
                return 1 
            if isValid(i,j,m,n,visited,board):
                visited[i][j]=1 
                if word[idx]==board[i][j]:
                    if help(m,n,i+1,j,idx+1,word,wlen,board,visited):
                        return 1
                    if help(m,n,i,j+1,idx+1,word,wlen,board,visited):
                        return 1
                    if help(m,n,i-1,j,idx+1,word,wlen,board,visited):
                        return 1
                    if help(m,n,i,j-1,idx+1,word,wlen,board,visited):
                        return 1 
                visited[i][j]=0 
            return 0
                
            return 0 
        m=len(board)
        n=len(board[0]) 
        visited=[] 
        for i in range(m):
            visited.append([0]*n) 
        setboard=set() 
        setstring=set()
        for i in range(m):
            for j in range(n):
                setboard.add(board[i][j]) 
        for x in word:
            setstring.add(x) 
        if not setstring.issubset(setboard) :
            return 0
        for i in range(m):
            for j in range(n):
                if board[i][j]==word[0] and help(m,n,i,j,0,word,len(word),board,visited):
                    return 1 
        return 0

#{ 
 # Driver Code Starts
if __name__ == '__main__':
	T=int(input())
	for tt in range(T):
		n, m = map(int, input().split())
		board = []
		for i in range(n):
			a = list(input().strip().split())
			b = []
			for j in range(m):
				b.append(a[j][0])
			board.append(b)
		word = input().strip()
		obj = Solution()
		ans = obj.isWordExist(board, word)
		if(ans):
			print("1")
		else:
			print("0")

# } Driver Code Ends