class Solution
{
    public:
    int const MOD = 1e9 +7;
    long long countWays(int n)
    {
        int dp[n+1];
        memset(dp , 0 , sizeof dp);
        dp[0]=1;
        for(int i =1;i<=n;i++){
            for(int j =1;j<=3;j++){
                if(i-j<0)continue;
                dp[i] = (dp[i] + dp[i-j])%MOD;
            }
        }
        return dp[n];
    }
};
