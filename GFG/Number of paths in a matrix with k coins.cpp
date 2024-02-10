class Solution {
public:
    long long int dp[100][100][100];
    long long int helper(int i ,int j , int k, vector<vector<int>> & arr){
        if(i<0 || j<0 || k<0)return 0;
        if(i==0 && j==0 && k==arr[0][0])return 1;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        return dp[i][j][k] = helper(i-1 ,j , k - arr[i][j] ,arr) + helper(i ,j-1 , k-arr[i][j],arr);
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        memset(dp ,-1, sizeof dp);
        return helper(n-1 ,n-1 ,k , arr);
    }
};
