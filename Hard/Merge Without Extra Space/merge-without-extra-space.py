#User function Template for python3

class Solution:
    
    #Function to merge the arrays.
    def merge(self,arr1,arr2,n,m):
        arr3=[]
        for i in range(n):
            arr3.append(arr1[i])
        for i in range(m):
            arr3.append(arr2[i])
            
        arr3.sort();
        for i in range(n):
            arr1[i]=arr3[i]
        for i in range(m):
            arr2[i]=arr3[i+n]
    



#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        n,m = map(int, input().strip().split())
        arr1 = list(map(int, input().strip().split()))
        arr2 = list(map(int, input().strip().split()))
        ob=Solution()
        ob.merge(arr1, arr2, n, m)
        print(*arr1,end=" ")
        print(*arr2)
# } Driver Code Ends