'''
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None

'''

class Solution:
    def constructTree(self, pre, post):
        def Ct(pre,pos):
            if pre==[] or pos==[]:
                return
            n=pre[0]
            root=Node(n)
            pos=pos[:-1]
            pre=pre[1:]
            if pre!=[]:
                mid=pos.index(pre[0])
                root.left=Ct(pre[:mid+1],pos[:mid+1])
                root.right=Ct(pre[mid+1:],pos[mid+1:])
            return root
        return Ct(preorder,postorder)
        