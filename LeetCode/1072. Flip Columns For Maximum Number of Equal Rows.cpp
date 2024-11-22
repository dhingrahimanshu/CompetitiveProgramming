class Solution {
public:
    int m1 = 0;
    bool areSame (vector<int> & a, vector<int> & b) {
        bool flag = true, flag2 = true;
        if (a.size() != b.size() && (a.size() + b.size() != m1)) return false;

        if (a.size() == b.size()) {
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) {
                    flag = false;
                    break;
                }
            }
        } else {
            flag = false;
        }

        if(flag) return true;
        if (a.size() + b.size() == m1) {
            vector<int> hash(301, 0);
            for (auto &it: a) {
                hash[it]++;
            }
            for (auto &it: b) {
                if(hash[it]) {
                    flag2=false;
                    break;
                }
            }
        } else {
            flag2 = false;
        }
        

        return (flag || flag2);
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        int n = (int) matrix[0].size();
        m1 = n;
        vector<vector<int>> stor(m);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    stor[i].push_back(j);
                }
            }
        }

        vector<int> vis(m , 0);
        for (int i = 0; i < m; i++) {
            if (vis[i]) continue;
            int temp = 1;
            vis[i] = 1;
            for (int j = i + 1; j < m; j++) {
                if(vis[j]) continue;
                if (areSame(stor[i], stor[j])) {
                    vis[j] = 1;
                    temp++;
                }
            }
            
            ans = max(ans, temp);
        }



        return ans;
    }
};
