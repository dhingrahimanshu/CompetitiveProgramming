class Solution {
public:
    int const MOD = 1e9 + 7;
    int dp[1001][1001];
    vector<vector<int>> hash;
    int helper (int level, int level2, vector<string> & words, string & target) {
        if (level2 == (int) target.size()) return 1;
        if (level == (int)words[0].size())  return 0;

        if (dp[level][level2] != -1) return dp[level][level2];

        dp[level][level2] = helper(level + 1, level2, words, target)%MOD;

        dp[level][level2] =  (dp[level][level2]%MOD + (int) (hash[level][target[level2] - 'a']*1ll*helper(level + 1, level2 + 1, words, target)%MOD)%MOD)%MOD;

        return dp[level][level2];
    }

    int numWays(vector<string>& words, string target) {
        memset(dp, -1, sizeof dp);
        int n = (int)words.size();
        int m = (int)words[0].size();
        // hash.clear();
        hash.resize(m, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hash[j][words[i][j] - 'a']++;
            }
        }
        return helper(0, 0, words, target);
    }
};
