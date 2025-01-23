class Solution {
public:
    int n,m;
    int dfs (int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        vis[x][y] = true;
        int ans = 1;

        for (int col = y + 1; col < n; col++) {
            if (grid[x][col] && !vis[x][col]) {
                ans += dfs(x, col, grid, vis);
                break;
            }
        }

        for (int row = x + 1; row < m; row++) {
            if (grid[row][y] && !vis[row][y]) {
                ans += dfs(row, y, grid, vis);
                break;
            }
        }

        for (int row = 0; row < x; row++) {
            if (grid[row][y] && !vis[row][y]) {
                ans += dfs(row, y, grid, vis);
                break;
            }
        }

        for (int col = 0; col < y; col++) {
            if (grid[x][col] && !vis[x][col]) {
                ans += dfs(x, col, grid, vis);
                break;
            }
        }
        return ans;
    }
    int countServers(vector<vector<int>>& grid) {
        m = (int) grid.size();
        n = (int)grid[0].size();


        vector <vector<bool>> vis(m, vector<bool>(n, false));

        int ans = 0;


        // [0,0,0,1,0,0,0,0,0],
        // [0,0,0,0,0,1,1,0,0],
        // [0,1,1,0,0,0,0,0,0],
        // [0,0,0,1,0,0,0,0,0],      
        // [0,1,0,1,0,0,1,0,0]


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] || !grid[i][j]) continue;
                int temp = dfs(i, j, grid, vis);
                if (temp > 1) {
                    ans += temp;
                }
            }
        }



        return ans;
    }
};
