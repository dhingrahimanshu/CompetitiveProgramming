class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = (int)nums.size();
        for(int i =0 ;i<n-1;i){
            if(nums[i]==0)return false;
            if((nums[i] + i +1)>=n)return true;
            int j = i +1 , val =0;
            for(int k = i+1;k<=(nums[i] + i);k++){
                if((k+ nums[k]) > val){
                    val = k + nums[k];
                    j  = k;
                }
            }
            i = j;
        }

        return true;
    }
};
