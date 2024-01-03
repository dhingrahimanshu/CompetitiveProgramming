class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = (int)matrix.size();
        int m = (int) matrix[0].size();
        int dp[n][m];
        int ans =0;
        
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                dp[i][j] = (matrix[i][j]-'0');
                if(dp[i][j]==0)continue;
                int temp =INT_MAX;
                if(i>0){
                    temp = min(temp , 1+dp[i-1][j]);
                }else{
                    temp =0;
                }
                if(j>0){
                    temp = min(temp , 1+dp[i][j-1]);
                }else{
                    temp =0;
                }
                if(i>0 && j>0){ 
                    temp = min(temp , 1+dp[i-1][j-1]);
                }else{
                    temp =0;
                }
                if(temp==INT_MAX)temp =0;
                dp[i][j] = max(dp[i][j] , temp);
                ans = max(ans , dp[i][j]);
            }
        }
        return ans*ans;
    }
};
