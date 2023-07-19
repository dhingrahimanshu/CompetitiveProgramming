class Solution {
public:
    int dp[301][301];

    int helper(int i , int j , vector<vector<char>> & arr){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(arr[i][j]=='1'){
            return dp[i][j] = 1+ min({helper(i-1 , j , arr) ,helper(i-1 , j-1 ,arr) , helper( i,j-1,arr)}); 
        }
        return dp[i][j]=0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
       memset(dp ,  -1 , sizeof dp); 
        int ans =0;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                ans = max(ans , helper(i , j , matrix));
            }
        }

       return ans*1ll*ans;
    }
};
