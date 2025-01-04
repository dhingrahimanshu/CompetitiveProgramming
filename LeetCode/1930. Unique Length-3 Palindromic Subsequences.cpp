class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = (int) s.size();
        int ans = 0;

        vector<vector<int>> pref(n, vector<int>(26, 0));

        vector <pair<int,int>> occ(26, {-1, -1});

        for (int i = 0; i < n; i++) {
            pref[i][s[i] - 'a']++;
            if (i) {
                for (int j = 0; j < 26; j++) {
                    pref[i][j] += pref[i-1][j];
                }
            }
            if (occ[s[i] - 'a'].first == -1) {
                occ[s[i] - 'a']= {i ,i};
            } else {
                occ[s[i] - 'a'].second = i;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (occ[i].first != -1) {
                int unique = 0;
                for (int j = 0; j < 26; j++) {
                    if (pref[max(0, occ[i].second - 1)][j] - pref[occ[i].first][j] > 0) {
                        unique++;
                    }
                }
                ans += unique;
            }
        }


        return ans;
    }
};
