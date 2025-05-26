/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        if(head->data>data){
            Node* newNode = new Node(data);
            Node* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
            return newNode;
            
        }
        Node* h=head;
        Node* temp=head->next;
        Node* p=h;
        
        while(temp!=h && temp->data<data){
            p=temp;
            temp=temp->next;
        }
        
        Node* newNode = new Node(data);
        newNode->next=p->next;
        p->next=newNode;
        return h;
    }
    
};