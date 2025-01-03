class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = (int)nums.size();
        long long sum = 0, curSum = 0;;
        int ans = 0;
        for (auto &it: nums) sum += it;
        for (int i = 0; i < n -1; i++) {
            sum -= nums[i];
            curSum += nums[i];
            if (curSum >= sum) ans++;
        }

        return ans;
    }
};
