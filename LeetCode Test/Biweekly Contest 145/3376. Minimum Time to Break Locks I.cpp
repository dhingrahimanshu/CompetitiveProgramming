class Solution {
public:
    int dp[(1<<8) + 1];

    int helper (int mask, vector<int> & strength, int &k, int destroyed) {
        if (destroyed == (int)strength.size()) return 0;
        if (dp[mask] != -1) return dp[mask];

        dp[mask] = 1e9;

        for (int i = 0; i < (int)strength.size(); i++) {
            if (mask & (1 << i)) continue;

            int energy = 1 + (k * destroyed);
            int time = (strength[i] + energy - 1) / energy;
            dp[mask] = min(dp[mask], time +  helper(mask|(1<<i), strength, k, destroyed + 1));
        }

        return dp[mask];
    }

    int findMinimumTime(vector<int>& strength, int K) {
        memset(dp, -1, sizeof dp);
        return helper(0, strength, K, 0);
    }
};
