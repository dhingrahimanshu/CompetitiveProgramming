class Solution {
public:
    int ans =0;
    void helper(int i , vector<int> & nums , int k , vector<int> & vis){
        if(i == nums.size()){
            ans++;
            return;
        }
        helper(i+1 , nums , k , vis);
        if(nums[i]-k <=0 ||  vis[nums[i] - k]==0){
            vis[nums[i]] = 1;
            helper(i+1 , nums , k , vis);
            vis[nums[i]] =0;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        vector<int> vis(1001 ,0);
        helper(0 , nums , k , vis);
        return ans-1;
    }
};
