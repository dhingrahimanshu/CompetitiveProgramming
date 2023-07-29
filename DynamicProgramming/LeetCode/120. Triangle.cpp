class Solution {
    public:
    int dp[201][201];

    int helper(int i , int j , vector<vector<int>> & triangle){
        
        if(i==(int)(triangle.size())){
            return 0;
        }
        if(j<0 || j>(i)){
            return 1e8;
        }
        return dp[i][j] = (dp[i][j]==-1)?triangle[i][j] + min(helper(i+1 , j , triangle) , helper(i+1 , j+1 , triangle)):dp[i][j];  
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp , -1 , sizeof dp);
        return helper(0 , 0  , triangle);
    }
};
