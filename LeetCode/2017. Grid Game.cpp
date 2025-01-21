class Solution {
public:
    long long getPref (int index, int l, int r, vector<vector<long long>> & pref) {
        if (l > r) return 0;

        if (!l) {
            return pref[index][r];
        }
        return pref[index][r] - pref[index][l-1];
    }

    long long gridGame(vector<vector<int>>& grid) {
        int n = 2;
        int m = grid[0].size();

        long long ans = 1e18;

        vector<vector<long long>> pref(2, vector<long long>(m, 0));


        for (int i = 0; i < m; i++) {
            pref[0][i] = grid[0][i];
            pref[1][i] = grid[1][i];

            if (i) {
                pref[0][i] += pref[0][i-1];
                pref[1][i] += pref[1][i-1];
            }
        }

        for (int i = 0; i < m; i++) {
            long long pre = getPref(0, i + 1, m-1, pref);
            long long suf = getPref(1, 0, i - 1, pref);
            
            ans = min(ans, max(pre,suf));
            
        }
        return ans;
    }
};
