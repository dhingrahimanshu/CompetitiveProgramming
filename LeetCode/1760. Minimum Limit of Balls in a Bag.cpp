class Solution {
public:

    int check (vector<int> & nums, int val) {
        int ans = 0;

        for (auto & it: nums) {
            ans += ceil(1.0*it / val) - 1;
        }

        return ans;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo = 1, hi = 1e9;
        int ans = 1e9;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (check(nums, mid) <= maxOperations) {
                hi = mid - 1;
                ans = min(ans, mid);
            } else {
                lo = mid + 1;
            }

        }
        return ans;
    }
};
