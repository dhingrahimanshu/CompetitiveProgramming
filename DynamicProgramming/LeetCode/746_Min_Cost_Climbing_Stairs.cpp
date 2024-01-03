class Solution {
public:
    int dp[1001];

    int helper(int i , vector<int> &arr){
       
        if(i==arr.size()){
            return 0;
        }
        if(i>(int)(arr.size())){
            return 1e8;
        }
        if(i==-1){
            return min(helper(i+1 , arr), helper(i+2 , arr));
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = arr[i] + min(helper(i+1 , arr), helper(i+2 , arr));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp , -1 , sizeof dp);
        return helper(-1 , cost);
    }
};
