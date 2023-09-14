class Solution {
  public:
    bool check(int a){
        if(!a%10)return 0;
        if(a%10==4)return 1;
        return check(a/10);
    }
  
  
    int countNumberswith4(int N) {
        vector<int> dp(N +1);
        dp[0] =0;
        for(int i=1;i<=N;i++){
            dp[i] = check(i) + dp[i-1];
        }
        return dp[N];
    }
};
