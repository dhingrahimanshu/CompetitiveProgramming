class Solution {
public:
    int dp[3001][3001];
    bool hash[3001];
    int helper (int level, int pattern_made, string & s, string & pattern) {
        if (pattern_made == (int)pattern.size()) {
            int ans = 0;
            for (int i = level; i< s.size();i++) {
                ans += hash[i];
            }
            return ans;
        }
        if (level == (int)s.size()) {
            return -1e4;
        }

        if (dp[level][pattern_made] != -1) return dp[level][pattern_made];

        if (hash[level] == 0) {
            return dp[level][pattern_made] = helper(level + 1, pattern_made + (s[level] == pattern[pattern_made]), s, pattern);
        }
        if ((s[level] != pattern[pattern_made])) {
            return dp[level][pattern_made] = 1 + helper(level + 1, pattern_made, s, pattern);
        }
        return dp[level][pattern_made] = max (1 + helper(level + 1, pattern_made, s, pattern), helper(level + 1, pattern_made + 1, s, pattern));

    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        memset (dp, -1 , sizeof dp);
        memset(hash, 0,sizeof hash); 
        for (auto &it : targetIndices) {
            hash[it] = 1;
        }
        return helper(0,0,source,pattern);
    }
};
