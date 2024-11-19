class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = 0;

        for (auto &it: nums) sum += it;

        int ans = 0;
        int sum2 = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int it = nums[i];
            sum2 += it;
            sum -= it;

            if (it == 0){
                if (sum2 == sum ) {
                    ans += 2;
                } else if (sum2 + 1 == sum || sum+1 == sum2) {
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
