class Solution{
    public:
    int dp[1001][1001];
    int helper(int n , int sum , vector<int> & cost){
        if(n>=(int)cost.size() || sum<0)return 0;
        if(dp[n][sum]!=-1)return dp[n][sum];
        dp[n][sum]= helper(n+1 , sum , cost);
        if(sum>=cost[n]){
            dp[n][sum] = max(dp[n][sum] , 1 + helper(n+ 1 , sum - cost[n] + 0.9*cost[n], cost));
        }
        return dp[n][sum];
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        memset(dp , -1 , sizeof dp);
        return helper(0 , total , cost);
    }
};
