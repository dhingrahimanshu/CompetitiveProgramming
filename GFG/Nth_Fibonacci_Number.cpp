class Solution {
  public:
    int nthFibonacci(int n){
        int dp[n+1];
        int const MOD = 1e9 +7;
        dp[0]=0; dp[1]=1;
        for(int i = 2;i<=n;i++){
            dp[i]  = (dp[i-1] + dp[i-2])%MOD;
        }
        return dp[n];
    }
};
