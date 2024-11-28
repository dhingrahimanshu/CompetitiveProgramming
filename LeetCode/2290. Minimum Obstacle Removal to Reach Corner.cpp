class Solution {
public:
    vector<pair<int,int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool isValid (int x, int y, int n ,int m) {
        if (x < 0 || y < 0 || x>=n || y>=m) return false;
        return true;
    }
    
    pair<int,int> convertToCoordinate (int x, int col) {
        int row = x / col;
        int column = x % col;
        return {row, column};
    }

    int convertFromCoordinate (pair <int,int>  cor, int col) {
        return ((col * cor.first) + cor.second);
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        vector <vector<int>> dis(m, vector<int>(n, 1e9));

        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pending;

        pending.push({0, 0});
        dis[0][0] = 0;
        while(pending.size()) {
            pair <int,int> pp = pending.top(); pending.pop();

            int val = pp.second;
            int dist = pp.first;

            pair <int,int> node = convertToCoordinate(val, n);

            for (auto &it: moves) {
                int x = node.first + it.first;
                int y = node.second + it.second;
                if (!isValid(x , y, m , n)) continue;
                int distance = grid[x][y] + dist;

                if (distance < dis[x][y]) {
                    dis[x][y] = distance;
                    pending.push({distance, convertFromCoordinate({x, y}, n)});
                }
            }
        }
        
        return dis[m-1][n-1];
    }
};
