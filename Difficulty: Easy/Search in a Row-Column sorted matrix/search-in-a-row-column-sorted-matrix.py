#User function Template for python3
class Solution:
	def matSearch(self, mat, tar):
	    n=len(mat)
	    m=len(mat[0])
		for i in range(n):
            if tar>mat[i][-1]:
                continue
            l=0
            r=m-1
            while l<=r:
                mid=(l+r)//2  
                # print(i,l,r,mid)
                if  mat[i][mid]==tar:
                    return 1
                elif mat[i][mid]>tar:
                    r=mid-1
                else:
                    l=mid+1 
        return 0


#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    t = int(data[0])
    index = 1
    for _ in range(t):
        r = int(data[index])
        c = int(data[index + 1])
        index += 2
        matrix = []
        for i in range(r):
            row = list(map(int, data[index:index + c]))
            matrix.append(row)
            index += c
        x = int(data[index])
        index += 1
        ob = Solution()
        if ob.matSearch(matrix, x):
            print("true")
        else:
            print("false")
        print("~")
# } Driver Code Ends