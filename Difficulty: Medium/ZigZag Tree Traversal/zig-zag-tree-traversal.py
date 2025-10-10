#User function Template for python3

'''
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''
class Solution:
    def __init__(self): 
        self.l=[]
        self.node=[] 
        self.res=[] 
        self.nextnode=[] 
    def levelOrder(self, root): 
        if(root==None):
            return [] 
        self.node.append(root)
        while(self.node!=[]):
            for x in self.node: 
                self.l.append(x.data)
                if x.left!=None:
                    self.nextnode.append(x.left) 
                if x.right!=None:
                    self.nextnode.append(x.right) 
            self.node=self.nextnode 
            self.nextnode=[]
            self.res.append(self.l)
            self.l=[]
        return self.res
    def zigZagTraversal(self, root):
        res=self.levelOrder(root)  
        op=[]
        for i in range(len(res)):
            if(i%2!=0): 
                res[i].reverse() 
            op+=res[i]
        return op
                
        






