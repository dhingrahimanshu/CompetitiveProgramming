class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int win[100001] , los[100001];
        memset(win , 0 , sizeof win);
        memset(los ,0 , sizeof los);
        for(auto & it : matches){
            win[it[0]]++;
            los[it[1]]++;
        }
        vector<vector<int>> ans(2);
        for(int i =1;i<=100000;i++){
            if(win[i] && !los[i]){
                ans[0].push_back(i);
            }else if(los[i]==1){
                ans[1].push_back(i);
            }
        }
       

        return ans;
    }
};
