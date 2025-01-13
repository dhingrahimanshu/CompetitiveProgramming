class Solution {
public:
    int dp[501][501][3];
    bool vis[501][501][3];

    int dr[2] = {0, 1};
    int dc[2] = {1, 0};

    bool isValid (int x, int y, int &m, int &n) {
        if (x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    };

    int helper (int row, int col, int state, int &m, int &n, vector<vector<int>>& coins) {
        if (row == m-1 && col == n-1) {
            if (state < 2 && coins[m-1][n-1] < 0) return 0;
            return coins[m-1][n-1];
        }

        if (vis[row][col][state]) {
            return dp[row][col][state];
        }

        dp[row][col][state] = -1e9;
        vis[row][col][state] = 1;

        for (int i = 0; i < 2; i++) {
            int nRow = row + dr[i] , nCol = col + dc[i];
            if (!isValid(nRow,nCol,m,n)) continue;
            dp[row][col][state] = max(dp[row][col][state], coins[row][col] + helper(nRow, nCol, state, m, n, coins));

            if (state != 2 && coins[row][col] < 0) {
                dp[row][col][state] = max(dp[row][col][state], helper(nRow, nCol, state + 1, m, n, coins));
            }
        }

        return dp[row][col][state];
    };

    int maximumAmount(vector<vector<int>>& coins) {
        memset(dp, -1, sizeof dp);
        memset(vis, 0, sizeof vis);

        int m = (int) coins.size();
        int n = (int) coins[0].size();

        return helper(0, 0, 0, m, n, coins);
    }
};
