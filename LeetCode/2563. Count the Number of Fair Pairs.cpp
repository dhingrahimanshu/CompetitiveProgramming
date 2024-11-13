class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());

        long long ans = 0;
        for (int i = 1; i<n; i++) {
            int lb = lower - nums[i];
            int ub = upper - nums[i];

            int a = (upper_bound(nums.begin(), nums.begin() + i, lb - 1) - nums.begin());;
            int b = (upper_bound(nums.begin(), nums.begin() + i, ub) - nums.begin());

            ans += (b - a);
        }

        return ans;
    }
};
