class Solution
{
    public:
    Node *sortedInsert(Node* head, int data){
       if(head==NULL){
           Node *a = new Node(data);
           a->next =a;
           return a;
       }
       Node *temp = head;
       if(data<head->data){
           while(temp->next!=head){
               temp = temp->next;
           }
           Node *t = new Node(data) , *t2 = temp->next;
           temp->next = t;
           t->next = t2;
           head = t;
           return head;
           
       }
       while(temp->next->data<data && temp->next!=head){
           temp = temp->next;
       }
       Node *t = new Node(data) , *t2 = temp->next;
       temp->next = t;
       t->next = t2;
       
       
       return head;
    }
};
