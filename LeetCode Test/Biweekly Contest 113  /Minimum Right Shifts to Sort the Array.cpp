class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n =(int) nums.size();
        if(is_sorted(nums.begin() , nums.end())){
            return 0;
        }
        for(int i =1 ;i<=n;i++){
            int last = nums[n-1];
            for(int j =n-1;j>0;j--){
                nums[j] = nums[j-1];
            }
            nums[0]=last;
            
            if(is_sorted(nums.begin() , nums.end())){
                return i;
            }
        }
        return -1;
    }
};
