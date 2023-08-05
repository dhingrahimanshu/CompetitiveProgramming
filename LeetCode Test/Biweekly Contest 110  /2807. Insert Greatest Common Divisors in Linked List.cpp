class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode * temp = head;
        while(head!=NULL && head->next!=NULL){
            int a= head->val;
            int b = head->next->val;
            int c = __gcd(a , b);
            ListNode *n = new ListNode(c);
            ListNode *uf = head->next;
            head->next = n;
            n->next = uf;
            head = uf;
        }
        
        return temp;
    }
};
