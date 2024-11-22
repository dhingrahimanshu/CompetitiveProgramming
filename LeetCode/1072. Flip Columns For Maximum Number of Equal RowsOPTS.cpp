class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mpp;

        int m = (int)matrix.size();
        int n = (int)matrix[0].size();

        for (auto &it : matrix) {
            string pattern;
            for (auto &it2: it) {
                if (it[0] == it2) {
                    pattern += "T";
                } else {
                    pattern += "F";
                }
            }
            mpp[pattern]++;
        }

        int ans = 0;

        for (auto & it: mpp) {
            ans = max(ans, it.second);
        }

        return ans;
    }
};
