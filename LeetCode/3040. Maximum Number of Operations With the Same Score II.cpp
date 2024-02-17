class Solution {
    public:
        int dp[2001][2001];


    int helper(int i , int j ,int sum , vector<int> & nums){
        if(i>=j)return 0;
        if(i+1 == j)return (sum == nums[i]+nums[j]);
        if(dp[i][j]!=-1)return dp[i][j];
        int ans =0;
        if((nums[i] + nums[i+1]) == sum){
            ans = 1 + helper(i+2 , j , sum , nums);
        }
        if((nums[j] + nums[j-1]) == sum){
            ans = max(ans , 1 + helper(i , j-2, sum , nums));
        }
        if((nums[i] + nums[j])==sum){
            ans = max(ans , 1 + helper(i+1 ,j-1 , sum , nums));
        }
        return dp[i][j] = ans;
    }

     int maxOperations(vector<int>& nums) {
        int n = (int)nums.size();
        if(n==1)return 0;
        memset(dp , -1  , sizeof dp);
        return 1 + max({helper(2 , n-1 , nums[0] + nums[1] , nums) , helper(1,n-2 , nums[0] + nums[n-1] , nums) , helper(0 ,n -3 , nums[n-1] +  nums[n-2] , nums)});

    }
};
