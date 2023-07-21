class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head==NULL || head->next==NULL){
            return head;
        }
        node * pre = NULL ,*temp=NULL;
        node *ans = head;
        for(int i =0 ;i<k;i++){
            if(head==NULL)break;
            temp = head->next;
            head->next = pre;
            pre =head;
            head=temp;

        }

        ans->next = reverse(head , k);
        return pre;
    }
};
