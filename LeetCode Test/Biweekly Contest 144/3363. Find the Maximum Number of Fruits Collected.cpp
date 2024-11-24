typedef long long ll;
class Solution {
public:
    ll dp[1001][1001];
    ll dp2[1001][1001];

    vector<pair<int,int>> moves1 = {{1, -1}, {1, 0}, {1, 1}};
    vector<pair<int,int>> moves2 = {{-1, 1}, {0, 1}, {1, 1}};

    bool isValid (int x, int y ,int n) {
        if (x < 0 || y < 0 || x>=n || y>=n) return false;
        return true;
    }

     ll helper (int row ,int col, int n, vector<vector<int>>& fruits) {
        if (row == n-1) {
            if (col == n-1) {
                return 0;
            } 
            return -1e9;
        }
        if (dp[row][col] != -1) return dp[row][col];

        dp[row][col] = -1e9;

        for (auto & it: moves1) {
            int x = row + it.first;
            int y = col + it.second;
            if (!isValid(x, y, n)) continue;
            dp[row][col] = max(dp[row][col], fruits[row][col] + helper(x, y, n, fruits));
        }


        return dp[row][col];
    }


    ll helper2 (int row ,int col, int n, vector<vector<int>>& fruits) {
        if (col == n-1) {
            if (row == n-1) {
                return 0;
            } 
            return -1e9;
        }
        if (dp2[row][col] != -1) return dp2[row][col];

        dp2[row][col] = -1e9;

        for (auto & it: moves2) {
            int x = row + it.first;
            int y = col + it.second;
            if (!isValid(x, y, n)) continue;
            dp2[row][col] = max(dp2[row][col], fruits[row][col] + helper2(x, y, n, fruits));
        }


        return dp2[row][col];
    }


    int maxCollectedFruits(vector<vector<int>>& fruits) {
        memset(dp, -1, sizeof dp);
        memset(dp2, -1, sizeof dp2);
        ll ans = 0;
        int n = (int) fruits.size();

        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }

        ans += helper(0, n-1, n, fruits);
        ans += helper2(n-1, 0, n, fruits);
        return (int)ans;
    }
};
