class Solution {
public:

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    bool isValid (int x, int y, int m, int n) {
        if (x < 0 || y < 0 || x>=m || y>=n) return false;
        return true;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = (int) isWater.size();
        int n = (int) isWater[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));

        queue <pair<int,int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (q.size()) {
            pair <int,int> node = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int x = node.first + dr[i], y = node.second + dc[i];

                if (!isValid(x, y, m, n)) continue;

                if (ans[x][y] == -1) {
                    ans[x][y] = 1 + ans[node.first][node.second];
                    q.push({x, y});
                }
            }
        }

        return ans;
    }
};
