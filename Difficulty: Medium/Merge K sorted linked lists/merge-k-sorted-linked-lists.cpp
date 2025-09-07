/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  Node* mergeTwoList(Node* l1, Node* l2){
        if(l2==NULL) 
            return l1; 
        if(l1==NULL) 
            return l2; 
        
        Node* res=NULL; 
        Node* temp=NULL;
        if (l1->data < l2->data){ 
            res=l1; 
            temp=l1; 
            l1=l1->next;
        } 
        else{
            res=l2; 
            temp=l2; 
            l2=l2->next;
        } 
        
        while(l1 && l2){
            if (l1->data < l2->data){  
            temp->next=l1; 
            l1=l1->next; 
            temp=temp->next;
            } 
        else{ 
            temp->next=l2; 
            l2=l2->next; 
            temp=temp->next; 
            } 
        } 
        while(l1){
            temp->next = l1; 
            temp=temp->next; 
            l1 = l1->next;
        } 
        while(l2){
            temp->next=l2; 
            l2=l2->next; 
            temp=temp->next;
        } 
        return res;
    } 
    
    Node* help(vector<Node*> lists)
    {
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1){
            return lists[0];
        }
        vector<Node* > mergeTwoListVector; 
        
        for(int i=0;i<lists.size();i=i+2){
            Node* l1 = lists[i];  
            Node* l2 = NULL;
            if(i+1<lists.size()) 
                l2 = lists[i+1]; 
           Node* merge = mergeTwoList(l1,l2); 
           mergeTwoListVector. push_back(merge);  
        }
        return help(mergeTwoListVector);
    }
    Node* mergeKLists(vector<Node*>& arr) {
        int K=arr.size();
        vector<Node*> v;
        for(int i=0;i<K;i++){
            v.push_back(arr[i]);
        }
        
        return help(v);
         
    }
};