class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());

        int right = 0, ans = 0;

        for (int left = 0; right < n &&  left < n; left++) {
            while (right < n && (nums[right] - nums[left]) <= 2*k) {
                right++;
            }
            ans = max(ans, right - left);
        }

        return ans;
    }
};
