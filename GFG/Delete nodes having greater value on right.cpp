class Solution
{
    public:
    Node *compute(Node *head)
    {
        
        Node *pre = NULL;
        
        while(head){
            Node *temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        int ma =0;
        
        Node * ans =NULL;
        
        while(pre){
            if(pre->data>=ma){
                Node * n = new Node(pre->data);
                n->next = ans;
                ans = n;
            }
            ma = max(ma , pre->data);
            pre = pre->next;
        }
        return ans;
        
    }
    
};
