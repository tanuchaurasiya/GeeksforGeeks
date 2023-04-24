from typing import Optional
from collections import deque

class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None

class Sol:
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

class Solution:
    def areAnagrams(self, node1 : Optional['Node'], node2 : Optional['Node']) -> bool:
        # code here 
        obj=Sol()
        obj2=Sol()
        res1=obj.levelOrder(node1)
        res2=obj2.levelOrder(node2) 
        # print(res1,res2)
        n1=len(res1) 
        n2=len(res2) 
        if n1!=n2:
            return 0 
        for i in range(n1):
            if set(res1[i])!=set(res2[i]):
                return 0 
        return 1


        



#{ 
 # Driver Code Starts
class Node:
    def __init__(self,val):
        self.data=val
        self.right=None
        self.left=None

# Function to Build Tree
def buildTree(s):
    #Corner Case
    if(len(s)==0 or s[0]=="N"):           
        return None
        
    # Creating list of strings from input 
    # string after spliting by space
    ip=list(map(str,s.split()))
    
    # Create the root of the tree
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    # Push the root to the queue
    q.append(root)                            
    size=size+1 
    
    # Starting from the second element
    i=1                                       
    while(size>0 and i<len(ip)):
        # Get and remove the front of the queue
        currNode=q[0]
        q.popleft()
        size=size-1
        
        # Get the current node's value from the string
        currVal=ip[i]
        
        # If the left child is not null
        if(currVal!="N"):
            
            # Create the left child for the current node
            currNode.left=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.left)
            size=size+1
        # For the right child
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        # If the right child is not null
        if(currVal!="N"):
            
            # Create the right child for the current node
            currNode.right=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root

def inputTree():
    treeString=input().strip()
    root = buildTree(treeString)
    return root
def inorder(root):
    if (root == None):
       return
    inorder(root.left);
    print(root.data,end=" ")
    inorder(root.right)

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        node1 = inputTree();
        
        
        node2 = inputTree();
        
        obj = Solution()
        res = obj.areAnagrams(node1, node2)
        
        result_val = 1 if res else 0
        print(result_val)

# } Driver Code Ends