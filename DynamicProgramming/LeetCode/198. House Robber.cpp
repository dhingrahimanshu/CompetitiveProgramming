class Solution {
public:
    int dp[101];
    int helper(int i , vector<int> & arr){
        if(i>=(int)arr.size()){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]= max(arr[i] + helper(i+2 , arr) , helper(i+1 , arr));
    }
    int rob(vector<int>& nums) {
        memset(dp , -1 , sizeof dp);
        return helper(0 , nums);
    }
};
