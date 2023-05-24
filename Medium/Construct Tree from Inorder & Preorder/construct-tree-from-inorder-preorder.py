#User function Template for python3

'''
# Node class

class Node:
    def __init__(self,val):
        self.data = val
        self.right = None
        self.left = None

'''

class Solution:
    
    def buildTree(self, preorder, inorder):
        if preorder==[] or inorder==[]:
            return None
        
        root=Node(preorder[0]) 
        idx=inorder.index(preorder[0]) 
        root.left=self.buildTree(preorder[1:idx+1],inorder[:idx])
        root.right=self.buildTree(preorder[idx+1:],inorder[idx+1:])
        
        return root
        
    def buildtree(self, inorder, preorder, n):
        return self.buildTree(preorder,inorder)
        





#{ 
 # Driver Code Starts
#Initial Template for Python 3

class Node:
    def __init__(self,val):
        self.data = val
        self.right = None
        self.left = None

def printPostorder(n):
    if n is None:
        return
    printPostorder(n.left)
    printPostorder(n.right)
    print(n.data, end=' ')

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        inorder = [ int(x) for x in input().split() ]
        preorder = [ int(x) for x in input().split() ]
        
        root = Solution().buildtree(inorder, preorder, n)
        printPostorder(root)
        print()

# } Driver Code Ends