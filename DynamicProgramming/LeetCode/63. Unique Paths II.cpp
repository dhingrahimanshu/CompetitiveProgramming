class Solution {
public:
    int dp[101][101];
    int helper(int i , int j , vector<vector<int>> &grid){
        if(i<0 || j<0){
            return 0;
        }
        if(i==0 && j==0){
            return (grid[i][j]==0);
        }
        if(grid[i][j]==1){
            return 0;
        }
        return dp[i][j]  = (dp[i][j]==-1)?helper(i-1 , j , grid) + helper(i , j-1 ,grid):dp[i][j];

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp , -1 , sizeof dp);
        int m = (int) obstacleGrid.size();
        int n = (int) obstacleGrid[0].size();
        return helper(m -1 , n -1 , obstacleGrid);
    }
};
