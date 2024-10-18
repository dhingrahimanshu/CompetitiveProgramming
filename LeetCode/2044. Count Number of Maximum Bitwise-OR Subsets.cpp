class Solution {
public:
    int dp[17][1000001];

    int helper (int level, int curOr, int targetOr, vector<int> & nums) {
        if (level == (int)nums.size()) return curOr == targetOr;

        if (dp[level][curOr] != -1) return dp[level][curOr];

        dp[level][curOr] = helper(level + 1, curOr, targetOr, nums) + helper(level + 1, curOr | nums[level], targetOr, nums);
        return dp[level][curOr];
    }

    int countMaxOrSubsets(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        int targetOr = 0;
        for (auto & it : nums) targetOr |= it;
        return helper(0,0,targetOr, nums);
    }
};
