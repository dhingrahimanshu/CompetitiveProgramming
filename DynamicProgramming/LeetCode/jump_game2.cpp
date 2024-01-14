class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int ans =0;
        int n = (int)nums.size();
        for(int i =0 ;i<n;){
            if((i + nums[i])>=n-1)return ans+1;
            int j = i+1 ,val =0;
            for(int k = i+1;k<=(nums[i] + i);k++){
                if((k + nums[k]) > val){
                    val = k + nums[k];
                    j = k;
                }
            }
            ans++;
            i = j;
        }


        return ans;
    }
};
