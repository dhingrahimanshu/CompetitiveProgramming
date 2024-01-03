// O-1 KnapSack problem Geeks For Geeks

class Solution
{
    public:
    int dp[1001][1001];
    Solution(){
        memset(dp, -1 ,sizeof dp);
    };
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       if(W==0 || n==0){
           return 0;
       }
       if(dp[n][W]!=-1){
           return dp[n][W];
       }
       if(wt[n-1]>W){
           return dp[n][W] = knapSack(W , wt , val ,n-1);
       }
       return dp[n][W] = max(val[n-1]+ knapSack(W-wt[n-1] , wt , val ,n-1) ,knapSack(W,wt ,val,n-1));
    }
};
