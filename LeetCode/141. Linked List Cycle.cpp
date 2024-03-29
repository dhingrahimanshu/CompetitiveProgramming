class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next == NULL)return false;
        ListNode *slow = head , *fast = head;

        do{
            fast = fast->next->next;
            slow = slow->next;
        }while(fast!=NULL && fast->next!=NULL && slow!=fast);
        return fast==slow;
    }
};
