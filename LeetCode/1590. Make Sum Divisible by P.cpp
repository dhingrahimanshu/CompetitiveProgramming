class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        int n = (int)nums.size();
        int ans = n;
        
        int target = 0;
        for(auto &it : nums) target = (target + it)%p;

        if (!target)return 0;
        unordered_map<int,int> mp;
        mp[0] = 0;
        for (int i = 1;i<=n;i++) {
            sum = (sum + nums[i-1])%p;
            
            int req = (sum - target + p)%p;
            if (mp[req] || req == 0) {

                ans = min(ans, i - mp[req]);
            }
            mp[sum] = i;
        }   

        return (ans == n?-1:ans);
    }
};
