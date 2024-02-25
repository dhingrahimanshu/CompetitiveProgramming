class Solution
{
    public:
    
    long long int count(long long int n)
    {
        vector<long long > dp(n+1);
        vector <int> arr = {3 ,5 , 10};
        dp[0]=1;    
        for(int i =0;i<3;i++){
            for(int j =1;j<=n;j++){
                if(j-arr[i] <0)continue;
                dp[j] += dp[j - arr[i]];
            }
        }
        dp[0]=0;
        return dp[n];
    }
};
