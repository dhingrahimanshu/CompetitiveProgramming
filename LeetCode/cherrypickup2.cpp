class Solution {
public:
    int dp[71][71][71];
    bool check(int i , int j1 , int j2 , int n , int m){
        if(i>=n || j1<0 || j2<0 || j1>=m || j2>=m)return 0;
        return 1;
    }

    int helper(int i ,int j1 , int j2 ,int n, vector<vector<int>> & grid){
        if(i==n-1){
            if(j1==j2)return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int ans =0;
        
        for(int x=-1;x<=1;x++){
            for(int y = -1;y<=1;y++){
                if(check(i+1 ,j1+x ,j2+y ,n,grid[0].size())==0)continue;
                ans = max(ans , helper(i+1 , j1 + x, j2 +y ,n , grid));
            }
        }
        if(j1 == j2){
            ans += grid[i][j1];
        }else{
            ans += grid[i][j1] + grid[i][j2]; 
        }


        return dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof dp);
        return helper(0 , 0 , (int)grid[0].size()-1 , (int)grid.size() ,grid);
    }
};
