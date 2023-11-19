class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        long long int n = (int)nums.size();
        long long int i =0 , ans =0 , cur =0;

        for(int j =0 ;j<n;j++){
            cur+=nums[j];
            while((j-i+1)*nums[j] - cur > k){
                cur-=nums[i];
                i++;
            }
            ans = max(ans ,j - i + 1);
        }

        return ans;
    }
};
