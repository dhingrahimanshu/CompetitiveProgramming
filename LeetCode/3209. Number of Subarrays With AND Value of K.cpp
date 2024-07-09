class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();
        long long int ans = 0;
        unordered_map<int,int> prev;
        for(int i = n-1;i>=0;i--){
            unordered_map<int,int> cur;
            cur[nums[i]]++;
            for(auto & it : prev){
                cur[it.first&nums[i]]+=it.second;
            }
            ans += cur[k];
            prev = cur;
        }
        return ans;
    }
};
