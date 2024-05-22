
class Solution {
public:
    ListNode * helper(ListNode * l1 , ListNode * l2 , int carry =0){
        if(l1==NULL && l2==NULL){
            if(carry)return new ListNode(carry);
            return NULL;
        }
        int val = carry;
        if(l1)val+=l1->val;
        if(l2)val+=l2->val;
        carry = val/10;
        val%=10;
        ListNode * n = new ListNode(val);
        n->next = helper(l1?l1->next:NULL , l2?l2->next:NULL , carry);
        return n;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1 , l2);
    }
};
