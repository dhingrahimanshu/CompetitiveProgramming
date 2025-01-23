class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int) grid[0].size();

        int ans = 0;

        vector <int> col(n, false);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    col[j]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int totalCol = 0, indCol = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    totalCol++;
                    if (col[j] > 1) {
                        ans++;
                    } else {
                        indCol++;
                    }
                }
            }
            if (totalCol > 1) {
                ans += indCol;
            }
        }

        return ans;
    }
};
