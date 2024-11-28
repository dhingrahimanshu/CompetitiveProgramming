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

        deque <int> pending;

        pending.push_back(0);
        dis[0][0] = 0;
        while(pending.size()) {
            int val = pending.front(); pending.pop_front();

            pair <int,int> node = convertToCoordinate(val, n);

            for (auto &it: moves) {
                int x = node.first + it.first;
                int y = node.second + it.second;
                if (!isValid(x , y, m , n)) continue;
                int distance = grid[x][y] + dis[node.first][node.second];

                if (distance < dis[x][y]) {
                    dis[x][y] = distance;
                    if (grid[x][y]) {
                        pending.push_back(convertFromCoordinate({x, y}, n));
                    } 
                    else {
                        pending.push_front(convertFromCoordinate({x, y}, n));
                    }
                }
            }
        }
        
        return dis[m-1][n-1];
    }
};
