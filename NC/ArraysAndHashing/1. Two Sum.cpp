class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> temp;
        int n = nums.size();
        for(int i =0 ;i<n;i++){
            int re = target - nums[i];
            if(temp[re]!=0){
                return {temp[re]-1 , i};
            }
            temp[nums[i]] = i+1;
        }
        return {-1 , -1};
    }
};
