class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo =1 , hi = nums.size()-1;
        while(lo<=hi){
            int mid = (lo + hi)/2;
            int count=0;
            for(auto & it : nums){
                if(it<=mid){
                    count++;
                }
            }
            if(count<=mid){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return lo;
    }
};
