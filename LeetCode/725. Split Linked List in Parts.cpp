/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode * nxt = head;
        int len = 0;
        while(nxt) {
            nxt = nxt->next;
            len++;
        }

        int part = len/k;
        vector<ListNode*> ans;
        int rem = len%k;
        ListNode * prev = head;
        cout << part << ' ' << rem << endl;
        while(head) {
            ans.push_back(prev);
            for (int i = 0;i<part-1;i++) {
                if(!head)continue;
                head = head->next;
            }
            if(part == 0) {
                prev = head->next;
                head->next = NULL;
                head = prev;
                continue;
            }
            if (rem) {
                head = head->next;
                rem--;
            }
            if(head) {
                prev = head->next;
                head->next = NULL;
                head = prev;
            }
            
        }

        int count = 0;
         while(ans.size()<k) {
            ans.push_back(NULL);
        }
        return ans;
    }
};
