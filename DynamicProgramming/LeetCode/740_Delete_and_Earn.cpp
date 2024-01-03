class Solution {
public:
    vector<int> dp;
    int helper(int i ,vector<int> & hash){
        if(i<=0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = max(helper(i-1 , hash) , helper(i-2 , hash) + i*hash[i]);
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> hash(1e4+1 , 0);
        for(int i =0 ;i<nums.size();i++){
            hash[nums[i]]++;
        }
        dp.resize(10001 , -1);
        return helper(10000 , hash);
    }
};
