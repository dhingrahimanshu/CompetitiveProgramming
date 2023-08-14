class Solution {
public:

    bool isvalid(int x , int y , int n , int m){
        if(x<0 || y<0 || x>=n || y>=m)return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> movements = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
        int n = grid.size();
        int m = grid[0].size();
        queue <pair<int,int>> pending;
        vector<vector<int>> lvl;
        lvl.resize(n , vector<int> (m , INT_MAX));
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j]==2){
                    lvl[i][j]=0;
                    pending.push({i,j});
                }
            }
        }
        while(pending.size()){
            pair<int,int> f = pending.front();pending.pop();
            for(auto it : movements){
                int x = f.first + it[0];
                int y = f.second +it[1];
                if(!isvalid(x ,y , n , m) || lvl[x][y]<=(lvl[f.first][f.second]+1) || grid[x][y]==0 || grid[x][y]==2)continue;
                grid[x][y]=2;
                lvl[x][y]= lvl[f.first][f.second]+1;
                pending.push({x ,y});
            }
        }
        int ans =0;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j]==1)return -1;
                if(grid[i][j]==2){
                    ans = max(ans , lvl[i][j]);
                }
            }
        }
        return ans;

    }
};
