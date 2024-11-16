class Solution {
public:
 
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = (int) nums.size();
        vector<int> ans(n - k + 1, -1);
        
        int j = 0;
        for (int i = 0; i <= n - k; i++) {
            j = max(j , i);
            while (j < n && (nums[j] - nums[i]) == (j - i)) {
                j++;
            }
            if ((j - i) >= k) {
                ans[i] = nums[i] + k - 1;
            }
        }

        return ans;
    }
};
