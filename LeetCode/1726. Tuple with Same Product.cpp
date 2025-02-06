class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        int n = (int) nums.size();
        int ans = 0;


        unordered_map <int,int> mpp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mpp[nums[i] * nums[j]]++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += mpp[nums[i] * nums[j]] - 1;
            }
        }


        return 4 * ans;
    }
};
