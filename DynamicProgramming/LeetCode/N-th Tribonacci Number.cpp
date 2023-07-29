class Solution {
public:
    int dp[38];
    Solution(){
        memset(dp , -1 , sizeof dp);
    }
    int tribonacci(int n) {
        if(n<=2){
            return min(1 , n);
        }
        return dp[n]=dp[n]==-1?(tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3)):dp[n];
    }
};
