class Solution
{
    public:
    int dp[1001][1001];
    
    int helper(int l , int r , int n , int m , string &s1 , string &s2){
        if(l==n || r==m){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        if(s1[l]==s2[r]){
            return dp[l][r] = 1+ helper(l+1 , r+1 , n , m , s1 , s2);
        }
        return dp[l][r]= max(helper(l+1 , r, n ,  m , s1 , s2) , helper(l , r+1 , n , m , s1  , s2));
    }
    
    int lcs(int n, int m, string s1, string s2)
    {
        memset(dp , -1 , sizeof dp);
        return helper(0 ,0 , n , m , s1 , s2);
    }
};
