class Solution {
public:
    int dp[1001][1001];

    int helper(int i , int j , string &s){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j] = helper(i+1 ,j-1 , s);
        }
        return dp[i][j] = 1+ min(helper(i+1 , j , s)  , helper(i , j-1 , s));
    }

    int minInsertions(string s) {
        memset(dp , -1 , sizeof dp);
        return helper(0 , s.size()-1 , s);
    }
};
