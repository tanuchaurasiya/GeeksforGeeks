#User function Template for python3

class Solution:
    # return true/false denoting whether the tree is Symmetric or not
    def isSymmetric(self, root):
        # Your Code Here
        def helper(r1,r2):
            if r1==None and r2==None:
                return 1 
            elif (r1==None and r2!=None) or (r1!=None and r2==None): 
                return 0 
            elif r1.data!=r2.data:
                return 0 
            elif helper(r1.left,r2.right)==0:
                return 0
            elif  helper(r1.right,r2.left)==0:
                return 0
            else:
                return 1 
        if root==None:
            return True
    
        return helper(root.left,root.right)


