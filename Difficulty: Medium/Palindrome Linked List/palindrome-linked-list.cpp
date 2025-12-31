/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    Node* findMiddle(Node* head){
        if(head==NULL) return head; 
        Node* slow = head;
        Node* fast = head->next;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    } 
    
    Node* reverse(Node* head){
        if(head==NULL) return NULL;
        
        Node* curr=head;
        Node* prev = NULL;
        Node* next=NULL;
        while(curr){
            next=curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        Node* h = head;
        Node* mid = findMiddle(h);
        Node* n1 = head;
        Node* n2 = mid->next; 
        mid->next=NULL; 
        n2 = reverse(n2); 
        
        while(n1 && n2){
            if(n1->data != n2->data) return false;
            n1= n1->next;
            n2= n2->next;
        }
        return true;
        
    }
};



