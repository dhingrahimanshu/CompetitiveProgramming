class Solution {
public:
    bool check(vector<int> & nums , int n ,int k , int val){
        int sum =0;
        for(int i =0;i<val;i++){
            sum += nums[i];
        }
        if((sum + k) >= val)return true;
        for(int i = val;i<n;i++){
            sum -= nums[i-val];
            sum += nums[i];
            if((sum + k) >= val)return true;
        }

        return false;
    }


    int longestOnes(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int low =0 , high = n;
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(check(nums , n , k  , mid)){
                ans = max(ans , mid);
                low = mid+1;
            }else{
                high = mid -1;
            }
        }
        return ans;
    }
};
