
Node *inPlace(Node *root)
{
    if(root==NULL || root->next==NULL){
        return root;
    }
    Node *temp =root, *rev =NULL;
    int size=0;
    while(temp!=NULL){
        Node *n = new Node(temp->data);
        n->next =rev;
        rev = n;
        temp=temp->next;
        size++;
    }
    Node *ans=new Node(1);
    Node *fans = ans;
    for(int i =0 ;i<size/2;i++){
        ans->next = new Node(root->data);
        ans=ans->next;
        ans->next = new Node(rev->data);
        ans=ans->next;
        root=root->next; rev=rev->next;
    }
    if(size&1){
        ans->next=new Node(root->data);
    }
    return fans->next;
    
}
