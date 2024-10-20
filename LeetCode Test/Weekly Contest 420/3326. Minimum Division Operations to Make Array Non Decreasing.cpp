class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = 0;
        for (int i = n - 2;i>=0;i--) {
            if (nums[i] > nums[i+1]) {
                int ans2 = -1;
                for (int j = 2;j*j<=nums[i];j++) {
                    if (nums[i] % j == 0) {
                        int second = nums[i] / j;
                        if (j <= nums[i+1]) {
                            ans2 = max(ans2, j);
                        }
                        if (second <= nums[i+1]) {
                            ans2 = max(ans2, second);
                        }
                        
                    }
                }
                if (ans2 > -1) {
                    ans += 1;
                    nums[i] = ans2;
                }else {
                    return -1;
                }
            } 
        }

        return ans;
    }
};
