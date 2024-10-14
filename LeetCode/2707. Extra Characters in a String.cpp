class Solution {
public:
    int dp[51];
    unordered_map <string,bool> mp;

    int helper (int level, string & s) {
        if (level == s.size()) return 0;

        if (dp[level] != -1) return dp[level];
        dp[level] = 1 + helper(level + 1, s);
        string temp;
        for (int i = level; i<s.size();i++) {
            temp += s[i];

            if (mp[temp]) {
                dp[level] = min(dp[level], helper(i + 1, s));
            }
        }
        return dp[level];
    }
    int minExtraChar (string s, vector<string>& dictionary) {
        memset (dp, -1, sizeof dp);
        for (auto & it: dictionary) {
            mp[it] = 1;
        }
        return helper (0, s);
    }
};
