class Solution{
public:
	ll dp[100001];
	int const MOD = 1e9+7;
	ll helper(int n){
	    if(n<0)return 0;
	    if(n<=1){
	        return n+1;
	    }
	    if(dp[n]!=-1)return dp[n];
	    
	    return dp[n] = (helper(n -1) + helper(n-2))%MOD;
	}
	
	ll countStrings(int n) {
	    memset(dp , -1 , sizeof dp);
	    return helper(n);
	}
};
