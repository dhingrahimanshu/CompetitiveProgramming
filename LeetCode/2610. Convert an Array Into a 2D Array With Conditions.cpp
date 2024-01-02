class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
     
        unordered_map <int,int> count;
        int n  = 0;
        for(auto & it : nums){
            count[it]++;
            n = max(n , count[it]);
        }
        vector<vector<int>> ans(n);
        for(int i =0 ;i<n;i++){
            for(auto & it : count){
                if(it.second>0){
                    ans[i].push_back(it.first);
                    it.second--;
                }
            }
        }
        return ans;

    }
};
