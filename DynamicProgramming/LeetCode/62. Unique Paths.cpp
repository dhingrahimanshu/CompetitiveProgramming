class Solution {
public:
    int dp[101][101];
    Solution(){
        memset(dp , -1 , sizeof dp);
    }
    int uniquePaths(int m, int n) {
        
       if(m<=0 || n<=0){
           return 0;
       }
       if(m==1 && n==1){
           return 1;
       }
       return dp[m][n] = (dp[m][n]==-1)?(uniquePaths(m-1 , n) + uniquePaths(m , n-1)):dp[m][n];
    }
};
