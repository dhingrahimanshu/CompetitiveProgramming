class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector <int> ans;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            int start = 0, end = n, step = 2;
            if (i % 2) {
                start = n - 1 - (n%2), end = -1, step = -2;
            }
            for (int j = start; (i%2)?(j>end):(j < end); j+=step) {
                ans.push_back(grid[i][j]);
            }
        }

        return ans;
    }
};
