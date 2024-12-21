
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue <TreeNode *> q;
        q.push(root);
        int level = 0;

        while (q.size()) {
            int n = (int) q.size();

            vector <TreeNode *> val;
            for (int i = 0; i < n; i++) {
                TreeNode * node = q.front(); q.pop();

                if (level % 2) {
                    val.push_back(node);
                }
                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
                
            }
            for (int i = 0; i < val.size() / 2; i++) {
                val[i]->val = (val[i]->val ^ val[val.size() - i - 1]->val);
                val[val.size() - i - 1]->val = (val[i]->val ^ val[val.size() - i - 1]->val);
                val[i]->val = (val[i]->val ^ val[val.size() - i - 1]->val);
            }
            level^=1;
        }


        return root;
    }
};
