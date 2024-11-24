class Solution {
public:
    int dp[101][101][101];

    int helper (int level, int op1, int op2, int k, int n, vector<int> &nums) {
        if (level == n) return 0;

        if (dp[level][op1][op2] != -1) return dp[level][op1][op2];
        
        dp[level][op1][op2] = nums[level] + helper(level + 1, op1, op2, k , n , nums);

        if (op1) {
            dp[level][op1][op2] = min(dp[level][op1][op2], (nums[level] + 1) / 2 + helper(level + 1, op1 - 1, op2, k, n , nums));
        }
        

        if (nums[level] >= k && op2) {

            dp[level][op1][op2] = min(dp[level][op1][op2], nums[level] - k + helper(level + 1, op1, op2 -1 , k, n , nums));

            if (op1) {
                int val = nums[level];
                val = (val + 1) / 2;

                if (val >= k) {
                    dp[level][op1][op2] = min(dp[level][op1][op2], val - k + helper(level + 1, op1 - 1, op2 - 1, k , n , nums));
                }

                int val2 = (nums[level] - k + 1) / 2;
                
                dp[level][op1][op2] = min(dp[level][op1][op2], val2 + helper(level + 1, op1 - 1, op2 - 1, k , n , nums));
                
            }
            
            
        }


        return dp[level][op1][op2];
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp, -1, sizeof dp);
        int n = (int) nums.size();
        return helper(0, op1, op2, k, n, nums);
    }
};
