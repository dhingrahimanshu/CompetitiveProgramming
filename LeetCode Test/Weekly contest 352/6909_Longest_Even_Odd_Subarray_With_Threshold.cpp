class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans =0;
        for(int i =0 ;i<n;i++){
            if(nums[i]&1 || nums[i]>threshold)continue;
            int j =i;
            while(j<n-1 && (nums[j]%2)!=(nums[j+1])%2 && nums[j+1]<=threshold){
                j++;
            }
            ans = max(ans , j-i+1);
        }
        return ans;
    }
};
