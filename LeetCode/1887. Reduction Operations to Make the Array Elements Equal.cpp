class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans =0;
        sort(nums.begin() , nums.end());
        int n = (int) nums.size();
        int counter =0;
        for(int i =0; i<n;){
            int j = i;
            while(j<n && nums[i]==nums[j]){
                j++;
            }
            ans += counter*(j-i);
            i = j;
            counter++;
        
        }
        return ans;
    }
};
