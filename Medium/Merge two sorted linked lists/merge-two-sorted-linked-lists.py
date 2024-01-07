#User function Template for python3
'''
	Function to merge two sorted lists in one
	using constant space.
	
	Function Arguments: head_a and head_b (head reference of both the sorted lists)
	Return Type: head of the obtained list after merger.

	{
		# Node Class
		class Node:
		    def __init__(self, data):   # data -> value stored in node
		        self.data = data
		        self.next = None
	}

'''
#Function to merge two sorted linked list. 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class S:
    def mergeTwoLists(self, l1 ,l2):
        h=Node(0) 
        res=h
        while(l1!=None and l2!=None): 
            if l1.data>l2.data:
                h.next=Node(l2.data) 
                h=h.next 
                l2=l2.next 
            elif l1.data<l2.data:
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
        
def sortedMerge(head1, head2):
    obj = S()
    return obj.mergeTwoLists(head1, head2) 


#{ 
 # Driver Code Starts
#Initial Template for Python 3
# Node Class
class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None

# Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    # creates a new node with given value and appends it at the end of the linked list
    def append(self, new_value):
        new_node = Node(new_value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node    
            return
        self.tail.next = new_node
        self.tail = new_node
        
# prints the elements of linked list
def printList(n):
    while n is not None:
        print(n.data, end=' ')
        n = n.next
    print()

if __name__ == '__main__':
    for _ in range(int(input())):
        n,m = map(int, input().strip().split())
        
        a = LinkedList() # create a new linked list 'a'.
        b = LinkedList() # create a new linked list 'b'.
        
        nodes_a = list(map(int, input().strip().split()))
        nodes_b = list(map(int, input().strip().split()))
        
        for x in nodes_a:
            a.append(x)
        
        for x in nodes_b:
            b.append(x)
        
        printList(sortedMerge(a.head,b.head))

# } Driver Code Ends