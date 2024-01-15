class Solution {
public:
    int dp[51][51];

    int helper(int l ,int r, vector<int> & values){
        if((r-l)<2)return 0;
        if(l+2 == r){
            return values[l]*values[r]*values[l+1];
        }
        if(dp[l][r]!=-1)return dp[l][r];
        dp[l][r] =1e9;

        for(int i=l+1;i<=r-1;i++){
            dp[l][r] =min(dp[l][r] , values[l]*values[r]*values[i] + helper(l ,i,values) + helper(i,r , values));
        }

        return dp[l][r];
    }

    int minScoreTriangulation(vector<int>& values) {
        memset(dp , -1 , sizeof dp);
        return helper(0 , values.size() -1 , values);
    }
};
