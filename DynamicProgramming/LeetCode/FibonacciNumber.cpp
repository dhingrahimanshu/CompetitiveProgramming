class Solution {
public:
    int dp[31];
    int helper(int n){
        if(n<=2){
            return min(1 , n);
        }
        return dp[n] = dp[n]==-1?helper(n-1)+helper(n-2):dp[n];
    }
    int fib(int n) {
        memset(dp , -1 , sizeof dp);
        return helper(n);
    }
};
