class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n = (int)nums.size();
        int i =0,j=0 , temp =0;
        while(j<n && nums[j]<0){
            j++;
            temp++;
        }
        i =j-1;
        
        while(i>=0 || j<n){
            if(j==n || (i>=0 && ((nums[i]*nums[i]) <=(nums[j]*nums[j])))){
                ans.push_back(1ll*nums[i]*nums[i]);
                i--;
            }else{
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        return ans;
    }
};
