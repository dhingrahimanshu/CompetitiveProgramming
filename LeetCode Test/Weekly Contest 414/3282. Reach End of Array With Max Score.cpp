typedef long long ll;
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        ll ans = 0;
        ll n = (int)nums.size();
        ll prevMax = nums[0];
        ll index = 0;
        for(int i = 1;i<n;i++) {
            if (prevMax < nums[i]) {
                ans += (i - index)*prevMax;
                prevMax = nums[i];
                index = i;
            }
        }
        ans += (n - 1 - index)*prevMax;
        return ans;
    }
};
