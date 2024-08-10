class Solution {
public:
    
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};
    void dfs(int i, int j, int row , vector<vector<int>> &vis , vector<vector<int>> &arr){
        if(i<0 || j<0 || i>=row || j>=row)return;
        if(vis[i][j] || arr[i][j])return;
        vis[i][j] = 1;     
        for(int k = 0;k<4;k++) {
            dfs(i + dr[k] , j + dc[k], row, vis, arr);
        }

    }
    int regionsBySlashes(vector<string>& grid) {
        int n = (int)grid.size();
        int rows = 3*n, cols = 3*n;
        vector<vector<int>> arr(rows,vector<int>(cols,0));
        for(int i = 0;i<rows;i+=3){
            for(int j = 0;j<cols;j+=3){
                if(grid[i/3][j/3] == ' ')continue;
                if(grid[i/3][j/3] == '/'){
                    arr[i][j+2] = 1;
                    arr[i+1][j+1] = 1;
                    arr[i+2][j] = 1;

                }else{
                    arr[i][j] = 1;
                    arr[i+1][j+1] = 1;
                    arr[i+2][j+2] = 1;
                }
            }
        }
        vector<vector<int>> vis(rows,vector<int>(rows,0));
        int ans = 0;
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(arr[i][j] || vis[i][j])continue;
                // cout << i << ' ' << j << endl;
                dfs(i , j,rows, vis,arr);
                ans++;
            }
        }

        // for(int i = 0;i<rows;i++){
        //     for(int j = 0;j<cols;j++){
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        return ans;
    }
};
