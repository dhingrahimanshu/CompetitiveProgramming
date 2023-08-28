Node *removeDuplicates(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *temp = head;
    while(head->next!=NULL && head->data==head->next->data){
        head=head->next;
    }
    temp->next = removeDuplicates(head->next);
    return temp;
}
