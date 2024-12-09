class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = (int) nums.size();
        vector <int> prefixSum(n, 0);

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + (nums[i]%2 == nums[i-1]%2);
        }

        for (auto &it: queries) {
            int l = it[0];
            int r = it[1];

            int special = prefixSum[r] - prefixSum[l];

            if (special) {
                ans.push_back(false);
            } else {
                ans.push_back(true);
            }
        }
        return ans;
    }
};
