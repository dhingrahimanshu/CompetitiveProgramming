class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int n = (int)nums.size();
        int j = 0;
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            if (i) {
                sum -= nums[i - 1];
            }
            while (j < n && sum < target) {
                sum += nums[j];
                j++;
            }

            if (sum >= target) {
                ans = min(ans, j - i );
            }
        }
        return (ans == 1e9)?0:ans;
    }
};
