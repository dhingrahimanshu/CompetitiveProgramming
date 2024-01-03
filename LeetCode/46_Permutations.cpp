class Solution {
public:
    vector<vector<int>> ans;

    void helper(int i  , vector<int> & nums){
        if(i == (int) nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j = i ;j<(int)nums.size();j++){
            swap(nums[j] , nums[i]);
            helper(i+1 , nums);
            swap(nums[j] , nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        helper(0 , nums);
        return ans;
    }
};
