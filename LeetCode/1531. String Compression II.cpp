class Solution {
public:
    int dp[101][101];

    int getStr (int n) {
        if (n<=1) return 0;
        if (n<=9) return 1;
        if (n<=99) return 2;
        return 3;
    }

    int helper(int level, int left, string & s) {
        if (level == (int)s.size()) return 0;
        if (dp[level][left] != -1) return dp[level][left];
        dp[level][left] = 1e9;
        if (left) {
            dp[level][left] = helper(level + 1, left - 1, s);
        }

        int swaps = left;
        int similar = 0;
        for (int i = level; i < (int)s.size(); i++) {
            if (s[i] != s[level]) {
                swaps--;
            } else {
                similar++;
            }
            if (swaps < 0) break;
            dp[level][left] = min(dp[level][left], 1 + getStr(similar) + helper(i + 1, swaps, s));
        }
        return dp[level][left];
     }

    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof dp);
        return helper(0, k, s);
    }
};
