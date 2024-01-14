class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size();
        int dp[n][2];
        memset(dp , 0 , sizeof dp);
        dp[0][0]= dp[0][1] =nums[0];
        for(int i =1;i<nums.size();i++){
            dp[i][0] = max({nums[i] , dp[i-1][0]*nums[i] , dp[i-1][1]*nums[i]});
            dp[i][1] = min({nums[i] , nums[i]*dp[i-1][0] , dp[i-1][1]*nums[i]});
        }
        int ans = -1e9;
        for(int i =0 ;i<n;i++){
            ans = max(ans , dp[i][0]);
        }
        return ans;
    }
};
