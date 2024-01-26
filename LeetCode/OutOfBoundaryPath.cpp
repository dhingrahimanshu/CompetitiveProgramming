class Solution {
public:
    int dp[51][51][51];
    int const MOD =1e9 +7;
    int helper(int i ,int j , int n ,int m , int mov){
        if(i<0 || j<0 || i>=n || j>=m)return 1;
        if(mov==0)return 0;
        if(dp[i][j][mov]!=-1)return dp[i][j][mov];
        
        return dp[i][j][mov] = ((helper(i+1 ,j ,n ,m ,mov-1) + helper(i ,j+1 ,n ,m,mov-1))%MOD + (helper(i-1 , j , n , m , mov-1) + helper(i , j-1 ,n ,m , mov-1))%MOD)%MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp , -1 , sizeof dp);
        return helper(startRow , startColumn ,m ,n, maxMove);
    }
};
