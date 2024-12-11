class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());

        vector <int> searchArea;
        int ans = 1;

        for (auto &it: nums) {
            searchArea.push_back(it - k);
            searchArea.push_back(k);
            searchArea.push_back(it + k);
        }

        for (auto &it: searchArea) {

            int l = lower_bound(nums.begin(), nums.end(), it - k) - nums.begin();
            int r = upper_bound(nums.begin(), nums.end(), it + k) - nums.begin() - 1;

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
