class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node * ans = new Node(0);
        Node *fans = ans;
        while(head1!=NULL && head2!=NULL){
            if(head1->data==head2->data){
                ans->next= new Node(head1->data);
                ans = ans ->next;
                head1 = head1->next;
                head2=head2->next;
            }else if(head1->data > head2->data){
                head2 = head2->next;
            }else{
                head1=head1->next;
            }
        }
        
        
        return fans->next;
    }
};
