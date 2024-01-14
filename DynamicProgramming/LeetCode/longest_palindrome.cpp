class Solution {
public:
    bool dp[1001][1001];
    bool vis[1001][1001];
    bool helper(int l, int r , string & s){
        if(l>r)return 0;
        if(l==r)return dp[l][r] =1;
        if(l+1 == r && s[l]==s[r])return dp[l][r]=1;
        if(vis[l][r])return dp[l][r];
        vis[l][r] =1;
        if(s[l]==s[r] && helper(l+1, r-1 ,s)){
            return dp[l][r] =1;
        }
        return dp[l][r] =0;
    }
    string longestPalindrome(string s) {
        int n = (int)s.size();
        memset(dp , 0 , sizeof dp);
        memset(vis , 0 , sizeof vis);
        helper(0 , n-1 , s);
        int val =0;
        pair <int,int> maxi;
        for(int i=0 ;i<n;i++){
            for(int j = i;j<n;j++){
                if(helper(i ,j , s) && (j-i+1)>val){
                    val = j-i+1;
                    maxi = {i,j};
                }
            }
        }
        string ans ;
        for(int i = maxi.first;i<=maxi.second;i++){
            ans+=s[i];
        }
        return ans;
    }
};
