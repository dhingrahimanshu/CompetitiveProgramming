class Solution {
public:
    vector<vector<int>> dp;
    int helper(int i , int j , vector<vector<int>> & matrix){
        if(j<0 || j>=(int)matrix[0].size()){
            return 1e5;
        }
        if((i+1)==(int)matrix.size()){
            return matrix[i][j];
        }
        return dp[i][j]= dp[i][j]==-101?(matrix[i][j] + min({helper(i+1 , j , matrix) , helper(i+1 , j+1,matrix), helper(i+1 , j-1 , matrix)})):dp[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        dp.resize(101 , vector<int>(101, -101));
        for(int i =0 ;i<(int)matrix[0].size() ; i++){
            ans = min(ans , helper(0 , i , matrix));
        }

        return ans;
    }
};
