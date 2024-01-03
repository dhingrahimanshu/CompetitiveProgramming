Node* deleteNode(Node *head,int x)
{
    if(x==1){
        return head->next;
    }
    Node *temp = head;
    x-=2;
    for(int i =0 ;i<x;i++){
        head = head->next;
    }

    head->next=head->next->next;
    return temp;
    
}
