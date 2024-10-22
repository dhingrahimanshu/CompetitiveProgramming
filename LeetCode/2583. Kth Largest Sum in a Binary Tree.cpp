class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long ans = 0;

        vector<long long> levels;
        queue <TreeNode*> pq;
        pq.push(root);
        while (pq.size()) {
            int n = (int)pq.size();
            long long sum = 0;
            for (int i = 0; i<n; i++) {
                TreeNode *node = pq.front(); pq.pop();
                sum += node->val;

                if (node->left) {
                    pq.push(node->left);
                }
                if (node->right) {
                    pq.push(node->right);
                }
            }
            levels.push_back(sum);
        }
        sort(levels.begin(), levels.end(), greater<long long>());

        return levels.size()<k?-1:levels[k-1];
    }
};
