typedef long long ll;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        int n = (int)nums.size();
        vector<int> mpp(1e5 + 1, 0);
        int unique = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
            unique++;
            if (mpp[nums[i]]++) {
                unique--;
            }
        }

        if (unique == k) {
            ans = max(ans, sum);
        }

        for (int i = k; i < n; i++) {
            sum -= nums[i-k];
            if (--mpp[nums[i-k]] == 0) {
                unique--;
            }
            if (!mpp[nums[i]]++) {
                unique++;
            }
            sum += nums[i];

            if (unique == k) {
                ans = max(ans, sum);
            }
        }


        return ans;
    }
};
