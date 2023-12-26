class Solution {
public:
    vector<vector<int>> ans;
    void helper(int i , vector<int> &candidates , int target , vector<int>&temp){      
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==(int)candidates.size() || target<0)return;
        int j = i;
        while(j<candidates.size() && candidates[i]==candidates[j]){
            j++;
        }
        helper(j, candidates , target , temp);
        temp.push_back(candidates[i]);
        helper(i+1 , candidates , target-candidates[i],temp);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin() , candidates.end());
        helper(0 , candidates , target , temp);
        return ans;
    }
};
