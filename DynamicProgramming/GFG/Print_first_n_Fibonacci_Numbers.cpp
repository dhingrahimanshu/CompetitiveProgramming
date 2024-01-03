class Solution
{
    public:
    
    vector<long long> printFibb(int n) 
    {
        vector<long long int> dp(n);
        
        dp[0]=dp[1]=1;
        for(int i =2;i<n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp;
    }
};
