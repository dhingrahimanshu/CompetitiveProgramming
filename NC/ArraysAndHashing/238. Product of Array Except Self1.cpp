class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int pro = 1;
        int z=0;
        int n = nums.size();
        for(int i =0 ;i<nums.size();i++){
            if(nums[i]==0){
                z++;
            }else{
                pro*=nums[i];
            }
        }
        for(int i =0 ;i<n;i++){
            if(z>=2){
                ans.push_back(0);
            }else if(z==1){
                if(nums[i]==0){
                    ans.push_back(pro);
                }else{
                    ans.push_back(0);
                }
            }else{
                ans.push_back(pro/nums[i]);
            }
        }

        return ans;
    }
};
