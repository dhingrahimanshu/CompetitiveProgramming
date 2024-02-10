class Solution {
public:
    int dp[1001][1001];
    bool helper(int i ,int j  , string &s){
        if(i>=j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]!=s[j])return dp[i][j] = 0;
        return dp[i][j] = helper(i+1 ,j-1 ,s);
    }
    int countSubstrings(string s) {
        int n = (int)s.size();
        int ans =0;
        memset(dp , -1 , sizeof dp);
        for(int i=0;i<n;i++){
            for(int j =i;j<n;j++){
                if(helper(i ,j , s)){
                    ans++;
                }
            }
        }

        return ans;
    }
};
