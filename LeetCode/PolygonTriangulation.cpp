class Solution {
public:
    int dp[51][51];

    int helper(int l ,int r , vector<int> & values){
        if(l+2 == r)return values[l]*values[r]*values[l+1];
        if(l+2 > r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans = 1e9;
        for(int i = l+1;i<r;i++){
            ans = min(ans, values[l]*values[r]*values[i] + helper(l ,i ,values) + helper(i ,r ,values));
        }
        return dp[l][r] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        memset(dp ,-1 , sizeof dp);
        return helper(0 , (int)values.size()-1 , values);
    }
};
