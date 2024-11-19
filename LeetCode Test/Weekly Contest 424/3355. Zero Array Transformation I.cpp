class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int) nums.size();
        vector<int>hash(n + 4, 0);

        for (auto & it: queries) {
            hash[it[0]]++;
            hash[it[1] + 1]--;
        }
        for (int i = 0; i < n;i++) {
            if (i) {
                hash[i] += hash[i-1];
            }
            if (hash[i] < nums[i]) return false;
        }

        return true;
    }
};
