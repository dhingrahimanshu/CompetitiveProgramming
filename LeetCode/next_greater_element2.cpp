class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n ,-1);
        stack <int> temp;
        for(int i=0 ;i<2*n;i++){
            int j = i%n;
            if(temp.empty()){
                temp.push(j);
            }else{
                while(temp.size() && nums[temp.top()]<nums[j]){
                    ans[temp.top()] = nums[j];
                    temp.pop();
                }
                temp.push(j);
            }
        }
        return ans;
    }
};
