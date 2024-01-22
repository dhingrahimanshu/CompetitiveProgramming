class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x = 0 , y =0;
        int n = (int)nums.size();
        for(int i =0 ;i<n;i++){
            x^=(i+1)^nums[i];
            y^=nums[i];
        }
        int diff = x&~(x-1);
        int set =0 , unset =0;
        for(int i =0 ;i<n;i++){
            if(diff&nums[i]){
                set^=nums[i];
            }else{
                unset^=nums[i];
            }
        }
        for(int i =1 ;i<=n;i++){
            if((diff)&i){
                set^=i;
            }else{
                unset^=i;
            }
        }
        for(int i  =0;i<n;i++){
            if(set == nums[i]){
                swap(set , unset);
                break;
            }
        }
        return {unset , set};
    }
};
