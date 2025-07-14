'''
# Node Class:
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''
class Solution:
    #Function to return a list containing the postorder traversal of the tree.
    def postOrder(self, root):
        if root==None:
            return [] 
        return self.postOrder(root.left)+self.postOrder(root.right)+[root.data]