class Solution{
public:
    bool isvalid(int i ,int j, int n ,int m){
        if(i<0 || j<0 || i>=n || j>=m)return 0;
        return 1;
    }
    int dp[501][501];
    int helper(int i , int j ,int n , int m , vector<vector<int>> & arr){
        if(isvalid(i ,j , n , m)==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        return dp[i][j] = arr[i][j] + max({helper(i ,j-1,n,m ,arr) , helper(i-1,j-1 ,n ,m,arr) , helper(i+1 , j-1  , n , m, arr)});
        
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        memset(dp , -1 , sizeof dp);
        for(int i= 0;i<n;i++){
            helper(i ,m-1 , n , m  ,M);
        }
        int ans =0;
        
        for(int i =0 ;i<n;i++){
            ans = max(ans , dp[i][m-1]);
        }
        return ans;
        
    }
};
