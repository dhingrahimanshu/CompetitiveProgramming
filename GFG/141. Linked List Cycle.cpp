class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return 0;
        ListNode *slow = head;
        ListNode *fast = head;
        
        do{
            
            fast=fast->next->next;
            slow = slow->next;
        }while(fast!=NULL && fast->next!=NULL && fast!=slow);
        return fast==slow;
    }
};
