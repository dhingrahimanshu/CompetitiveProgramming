class Solution
{
    public:
    
    Node* pairWiseSwap(struct Node* head) 
    {
        if(!head || !head->next) return head;
        Node * ans = new Node(0);
        Node *fans = ans;
        
        while(head && head->next){
            Node *temp = head->next;
            ans->next = temp;
            head->next = temp->next;
            temp->next =head;
            ans = head;
            head = head->next;
        }
        
        
        
        return fans->next;
    }
};

