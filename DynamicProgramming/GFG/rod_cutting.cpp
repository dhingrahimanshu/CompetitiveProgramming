class Solution{
  public:
    int dp[1001];
    
    int helper(int n , int price[]){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        dp[n]=0;
        for(int i =0;i<n;i++){
            dp[n] = max(dp[n] , price[i] + helper(n- i -1 , price));
        }
        return dp[n];
    }
    
    int cutRod(int price[], int n) {
        memset(dp ,-1 , sizeof dp);
        return helper(n , price);
    }
};
