class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = (int) nums.size();
        int ans = 1e9;

        for (int i = 0; i <= n - l; i++) {
            int sum = 0;
            for(int j = i; j < n && j < i + r; j++) {
                sum += nums[j];
                if ((j - i + 1)>=l && sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }
        return (ans==1e9?-1:ans);
    }
};
