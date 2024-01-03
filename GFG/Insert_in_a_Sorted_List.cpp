class Solution{
  public:
    Node *sortedInsert(struct Node* head, int data) {
        if(head==NULL || head->data >=data){
            Node *n = new Node(data);
            n->next = head;
            return n;
        }
        Node *pre =NULL;
        Node *temp  = head;
        while(temp && temp->data<data){
            pre = temp;
            temp = temp->next;
        }
        Node * uf = pre->next;
        Node *n = new Node(data);
        pre->next=n;
        n->next =uf;
        return head;
    }
};
