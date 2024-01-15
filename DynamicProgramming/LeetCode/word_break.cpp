class Solution {
public:
    int dp[301][301];
    unordered_map <string ,bool> check;
    int helper(int l , int r , string &s){
        
        if(dp[l][r]!=-1) return dp[l][r];
        string temp;
        for(int i= l;i<=r;i++)temp+=s[i];
        if(check[temp]) return dp[l][r]=1;
        bool ans =0;
        for(int i = l;i<r;i++){
            ans|=(helper(l , i ,s)&helper(i+1 ,r ,s));
        }
        return dp[l][r] = ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp , -1 , sizeof dp);
        for(auto & it : wordDict){
            check[it]=true;
        }
        return helper(0 , s.size() -1 , s);
    }
};
