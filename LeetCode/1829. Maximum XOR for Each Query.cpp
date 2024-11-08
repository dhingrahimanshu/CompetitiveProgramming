class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;

        int n = (int)nums.size();

        int target = (1<<maximumBit) - 1;
        int xo = 0;

        for (auto &it: nums) {
            xo ^= it;
        }

        for (int i = n -1; i>=0; i--) {
            ans.push_back(xo ^ target);
            xo ^= nums[i];
        }


        return ans;
    }
};
