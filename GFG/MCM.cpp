class Solution{
public:
    int dp[101][101];
    int helper(int l , int r , int arr[]){
        if(l+1 >= r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        dp[l][r] =2e9;
        for(int i =l+1;i<r;i++){
            dp[l][r] =min(dp[l][r] , arr[l]*arr[r]*arr[i] + helper(l ,i,arr) + helper(i,r,arr));
        }
        return dp[l][r];
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp , -1 , sizeof dp);
        return helper(0 , N-1 , arr);
    }
};
