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
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        queue <TreeNode *> q;
        q.push(root);

        int ans = 0;

        while (q.size()) {
            vector<int> temp;
            int n = (int)q.size();

            // unordered_map <int, TreeNode *> ref;
            unordered_map <int, int> pos;
            for (int i = 0; i < n; i++) {
                TreeNode * node = q.front(); q.pop();

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
                temp.push_back(node->val);
                pos[node->val] = i;
            }

            vector<int> temp2(temp);
            sort(temp2.begin(), temp2.end());

            for (int i = 0; i < n; i++) {
                if (temp[i] != temp2[i]) {

                    int changing = temp[i];
                    int changingWith = temp2[i];

                    swap(temp[i], temp[pos[temp2[i]]]);
                    pos[changing] = pos[changingWith];
                    ans++;
                }
            }
            
        }


        return ans;
    }
};
