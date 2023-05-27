#User function Template for python3

class Solution:
    def modify_the_list(self, head):
        def reverse(head,s,e,middle):
            curr=head 
            next=None
            prev=middle
            while(curr!=None and s<e):
                next=curr.next 
                curr.next=prev
                prev=curr
                curr=next 
                s+=1
            head=prev 
            return head
        n=0 
        t=head
        while t:
            n+=1 
            t=t.next 
        t=head
        middle=head
        i=0
        while i<n//2:
            middle=middle.next
            i+=1
        # print(n) 
        middle1=middle
        middle2=middle
        t=reverse(t,0,n//2,middle1)
        t1=t
        # while t:
        #     print(t.data, end=" ") 
        #     t=t.next
        # print() 
        # while middle:
        #     print(middle.data, end=" ")
        #     middle=middle.next 
        # print()
        # print(middle.data)
        
        if n%2==1:
            while middle.next:
                var=t.data 
                t.data=middle.next.data-t.data 
                middle.next.data=var
                middle=middle.next
                t=t.next  
            head=reverse(t1,0,n//2,middle2) 
            return head 
        else:
            while middle:
                var=t.data 
                t.data=middle.data-t.data 
                middle.data=var
                middle=middle.next
                t=t.next  
            head=reverse(t1,0,n//2,middle2) 
            return head 
            
        
            
    
        
        
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

class Node:
    def __init__(self, x):
        self.data = x
        self.next = None


def modify_the_list(head):
    current = head
    while current is not None:
        if current.next is not None and current.data == current.next.data:
            current.next = current.next.next
        else:
            current = current.next
    return head


def print_list(head):
    temp = head
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.next
    print()


t = int(input())
while t > 0:
    n = int(input())
    linked_list_arr = list(map(int, input().split()))
    head = None
    temp = None
    for a in linked_list_arr:
        new_node = Node(a)
        if head is None:
            head = new_node
        else:
            temp.next = new_node
        temp = new_node
    head = Solution().modify_the_list(head)
    print_list(head)
    t -= 1
# } Driver Code Ends