class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> & arr , int i){
        int n = (int)(arr.size());
        if((i+1)>=n){
            ans.push_back(arr);
            return;
        }
        for(int j = i;j<n;j++){
            swap(arr[i],arr[j]);
            helper(arr , i+1);
            swap(arr[i] , arr[j]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums , 0);
        return ans;
    }
};
