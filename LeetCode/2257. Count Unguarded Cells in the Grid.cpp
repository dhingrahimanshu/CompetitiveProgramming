class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>>isGuarded (m, vector<bool> (n , false));
        int ans = 0;

        set <pair<int,int>> g, w;
        for (auto &it : guards) g.insert({it[0], it[1]});
        for (auto &it : walls) w.insert({it[0], it[1]});

        for (int i = 0; i < m; i++) {
            bool isProtected = false;
            for (int j = 0; j < n; j++) {
                if (g.find({i,j}) != g.end()) {
                    isProtected = true;
                }

                if (w.find({i,j}) != w.end()) {
                    isProtected = false;
                }
                isGuarded[i][j] = isGuarded[i][j] || isProtected;
            }
            isProtected = false;
            for (int j = n-1; j >=0 ; j--) {
                if (g.find({i,j}) != g.end()) {
                    isProtected = true;
                }

                if (w.find({i,j}) != w.end()) {
                    isProtected = false;
                }
                isGuarded[i][j] = isGuarded[i][j] || isProtected;
            }
        }


        for (int i = 0; i < n; i++) {
            bool isProtected = false;
            for (int j = 0; j < m; j++) {
                if (g.find({j,i}) != g.end()) {
                    isProtected = true;
                }

                if (w.find({j, i}) != w.end()) {
                    isProtected = false;
                }
                isGuarded[j][i] = isGuarded[j][i] || isProtected;
            }
            isProtected = false;
            for (int j = m-1; j>=0 ; j--) {
                if (g.find({j, i}) != g.end()) {
                    isProtected = true;
                }

                if (w.find({j, i}) != w.end()) {
                    isProtected = false;
                }
                isGuarded[j][i] = isGuarded[j][i] || isProtected;
            }
        }
        

        for (auto &it: isGuarded) {
            for (auto it2 : it) {
                if (!it2) ans++;
            }
        }
        return ans - (int) walls.size();
    }
};
