class Solution
{
    public:
    int dp[1001][1001];
    int const MOD = 1e9 +7;
    int helper(int i ,int j , string s , string t){
        if(j==-1)return 1;
        if(i==-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s[i] == t[j]){
            ans = helper(i-1 , j-1 , s , t);
        }
        ans = (ans + helper(i-1 , j , s ,t))%MOD;
        return dp[i][j] = ans;
    }
    int subsequenceCount(string s, string t)
    {
      memset(dp , -1  ,sizeof dp);
      int n = (int)s.size() , m = (int)t.size();
      return helper(n-1 , m-1 , s , t);
    }
};
 
