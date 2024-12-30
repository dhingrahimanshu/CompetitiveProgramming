class Solution {
public:

    int dp[100001];
    int const MOD = 1e9 + 7;
    int LOW, HIGH, ZERO,ONE;

    int helper (int level) {
        if (dp[level] != -1) return dp[level];

        dp[level] = (level >= LOW);

        if (level + ONE <= HIGH) {
            dp[level] = (dp[level] + helper(level + ONE))%MOD;
        }

        if (level + ZERO <= HIGH) {
            dp[level] = (dp[level] + helper(level + ZERO))%MOD;
        }

        return dp[level];
    }


    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof dp);
        LOW = low, HIGH = high, ZERO = zero, ONE = one;

        return helper(0);
    }
};
