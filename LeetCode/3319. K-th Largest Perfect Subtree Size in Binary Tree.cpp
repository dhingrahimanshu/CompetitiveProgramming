class Solution {
public:
    vector<int> ans;
    pair<int,int> helper (TreeNode* root) {
        if (root == NULL) {
            return {0, 1};
        }
        if (!root->left && !root->right) {
            ans.push_back(1);
            return {1,1};
        }
        pair<int,int> left = helper(root->left);
        pair<int,int> right = helper(root->right);

        if (root->left == NULL || root->right == NULL) {
            return {left.first + right.first + 1, 0};
        }
        if (left.second && right.second && left.first == right.first) {
            ans.push_back(left.first + right.first + 1);
        }

        pair<int,int> temp = {left.first + right.first + 1, left.second && right.second && left.first == right.first};
        return temp;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        ans.clear();
        helper(root);
        
        sort(ans.begin(), ans.end(), greater<int>());
        // for (auto & it : ans) cout << it << ' ';
        // cout << endl;
        if (k > ans.size())return -1;
        return ans[k-1];
    }
};
