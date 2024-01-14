class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        vector<pair<int,int>> dp(n);
        int lis =0;

        for(int i =0 ;i<n;i++){
            dp[i] = {1 , 1};
            int val =0;
            for(int j =0;j<i;j++){
                if(nums[j]<nums[i])val = max(val , dp[j].first);
            }
            dp[i].first= val+1;
            if(dp[i].first > 1){
                dp[i].second =0;
            }
            for(int j =0;j<i;j++){
                if(nums[j]<nums[i] && dp[j].first==val){
                    dp[i].second += dp[j].second;
                }
            }
            lis = max(lis , val +1);
        }
        int ans =0;
        for(int i=0 ;i<n;i++){
            if(dp[i].first == lis)ans +=dp[i].second;
        }
        return ans;

    }
};
