class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n = nums.size();
        vector<int> pre(n+1 ,1), suf(n+1 , 1);
        for(int i =0 ;i<n;i++){
            pre[i+1] = pre[i]*nums[i];
        }
        for(int i = n-1;i>=0;i--){
            suf[i] = suf[i+1]*nums[i];
        }
        for(int i =0 ;i<n;i++){
            ans[i] = pre[i]*suf[i+1];
        }
        return ans;
    }
};
