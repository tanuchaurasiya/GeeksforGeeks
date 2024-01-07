#User function Template for python3

'''
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
'''

class Solution:
    def reverse(self, head):
        curr=head
        prev=None
        next=None
        while(curr):
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        return prev
    def mergeTwoLists(self, l1 ,l2):
        h=Node(0) 
        res=h
        while(l1!=None and l2!=None): 
            if l1.data<l2.data:
                h.next=Node(l2.data) 
                h=h.next 
                l2=l2.next 
            elif l1.data>l2.data:
                h.next=Node(l1.data) 
                h=h.next 
                l1=l1.next 
            else:
                h.next=Node(l1.data) 
                h=h.next 
                h.next=Node(l2.data) 
                h=h.next 
                l1=l1.next 
                l2=l2.next 
        while l1!=None:
            h.next=Node(l1.data) 
            h=h.next 
            l1=l1.next 
        
        while l2!=None:
            h.next=Node(l2.data) 
            h=h.next 
            l2=l2.next 
            
        return res.next 
        
    def mergeResult(self, h1, h2):
        h1 = self.reverse(h1)
        h2 = self.reverse(h2)
        return self.mergeTwoLists(h1, h2) 


#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class Llist:
    def __init__(self):
        self.head=None
    
    def insert(self,data,tail):
        node=Node(data)
        
        if not self.head:
            self.head=node
            return node
        
        tail.next=node
        return node
        

def printList(head):
    while head:
        print(head.data,end=' ')
        head=head.next
        
if __name__ == '__main__':
    t=int(input())
    
    for tcs in range(t):
        
        n1,n2=[int(x) for x in input().split()]
        
        arr1=[int(x) for x in input().split()]
        ll1=Llist()
        tail=None
        for nodeData in arr1:
            tail=ll1.insert(nodeData,tail)
            
            
        arr2=[int(x) for x in input().split()]
        ll2=Llist()
        tail=None
        for nodeData in arr2:
            tail=ll2.insert(nodeData,tail)
        
        
        ob = Solution()
        resHead=ob.mergeResult(ll1.head,ll2.head)
        printList(resHead)
        print()
        
    
    
# } Driver Code Ends