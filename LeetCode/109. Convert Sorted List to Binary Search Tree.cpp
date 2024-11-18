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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode * helper (ListNode * head , int n) {
        if (!n) return NULL;
        if (n == 1) return new TreeNode(head->val);

        ListNode * temp = head;
        for (int i = 0; i < n/2;i++) {
            temp = temp->next;
        }

        TreeNode *root = new TreeNode(temp->val);
        root->left = helper(head, n / 2);
        root->right = helper(temp->next, n - (n / 2) - 1);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode * temp = head;

        while(temp) {
            temp = temp->next;
            n++;
        }
        return helper (head, n);
    }
};
