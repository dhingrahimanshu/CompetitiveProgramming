class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i =0,j=0;
        int n = (int)nums.size();
        while(i<n && j<n){
            while(i<n && nums[i]%2==0){
                i++;
            }
            while(j<n && nums[j]%2){
                j++;
            }
            if(i<j && i<n && j<n){
                swap(nums[i] , nums[j]);
            }
            if(i>j) {
                j = i+1;
            }
        }
        return nums;
    }
};
