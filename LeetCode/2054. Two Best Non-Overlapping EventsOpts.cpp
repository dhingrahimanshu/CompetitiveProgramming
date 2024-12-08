class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans = 0, maxVal = 0;

        vector <vector<int>> sweep;

        for (auto &it: events) {
            sweep.push_back({it[0], 0, it[2]});
            sweep.push_back({it[1], 1, it[2]});
        }

        sort(sweep.begin(), sweep.end());

        for (auto &it: sweep) {
            if (!it[1]) {
                int temp = it[2] + maxVal;
                ans = max(ans, temp);
            } else {
                maxVal = max(maxVal, it[2]);
            }
        }

        return ans;
    }
};
