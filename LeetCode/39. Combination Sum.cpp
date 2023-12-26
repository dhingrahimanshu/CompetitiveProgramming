class Solution {
public:
    vector<vector<int>> ans;
    void helper(int i , vector<int> &arr , int target , vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==(int)arr.size()){
            return;
        }
        int m = (int)temp.size();
        helper(i+1 , arr , target , temp);
        while(target>0){
            target-=arr[i];
            temp.push_back(arr[i]);
            helper(i+1 , arr , target , temp);
        }
        while((int)temp.size()!=m){
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        helper(0 , candidates , target ,temp);
        return ans;
    }
};
