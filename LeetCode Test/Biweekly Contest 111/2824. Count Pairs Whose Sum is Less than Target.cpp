class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans=0;
        int n = (int)nums.size();
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i]+nums[j] < target){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
