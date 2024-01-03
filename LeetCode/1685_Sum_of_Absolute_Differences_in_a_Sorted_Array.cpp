class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum =0;
        for(auto & it : nums){
            sum+=it;
        }
        int sum2=0;
        std::vector<int> ans;
        int n = (int)nums.size();
        for(int i= 0 ;i<n;i++){
            ans.push_back(abs(sum2 - nums[i]*i) + abs(sum - sum2 - nums[i]*(n-i)));
            sum2+=nums[i];
        }
        return ans;
        
    }
};
