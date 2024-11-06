class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int prevSegMax = 0;

        int curMax = nums[0];
        int curMin = nums[0];
        int curBits = __builtin_popcount(nums[0]);

        for (int i = 1; i < (int)nums.size(); i++) {
            if (curBits == __builtin_popcount(nums[i])) {
                curMax = max(curMax, nums[i]);
                curMin = min(curMin, nums[i]);
            } else {
                if (curMin <  prevSegMax) {
                    return false;
                }
                prevSegMax = curMax;

                curMax = nums[i];
                curMin = nums[i];
                curBits = __builtin_popcount(nums[i]);
            }
        }
        if (curMin <  prevSegMax) {
            return false;
        }


        return true;
    }
};
