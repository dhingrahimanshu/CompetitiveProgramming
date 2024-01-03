class Solution {
  public:
    int countNumberswith4(int N) {
        if(N<4)return 0;
        int d = log10(N);
        
        vector<int> dp(d+1);
        dp[0]=0;
        dp[1]=1;
        
        for(int i =2;i<=d;i++){
            dp[i] = (dp[i-1]*9 + ceil(pow(10 ,i-1)));
        }
        
        int p = pow(10 , d);
        
        int msd = N/p;
        
        if(msd==4) return (msd)*dp[d] + N%p +1;
        
        if(msd<4) return msd*dp[d] + countNumberswith4(N%p);
        
        return (msd-1)*dp[d] + p + countNumberswith4(N%p);
    }
};
