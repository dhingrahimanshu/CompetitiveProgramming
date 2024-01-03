class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusting(n+1 , 0) , trusted_by(n+1 , 0);
        for(auto & it : trust){
            trusting[it[0]]++;
            trusted_by[it[1]]++;
        }
        for(int i = 1;i<=n;i++){
            if(trusting[i]==0 && trusted_by[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};
