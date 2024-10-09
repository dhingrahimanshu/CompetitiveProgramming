class Solution {
public:
    int dp[51][51];

    int helper (int l, int r, vector<int> & values) {
        if (l + 1 >= r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        dp[l][r] = 1e9;

        for (int x = l+1; x <= r-1; x++) {
            dp[l][r] = min(dp[l][r], values[l]*values[x]*values[r] + helper(l,x, values) + helper(x,r, values));
        }

        return dp[l][r];
    }

    int minScoreTriangulation(vector<int>& values) {
        memset(dp, -1, sizeof dp);

        return helper(0, (int)values.size() - 1, values);
    }
};
