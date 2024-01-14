class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(10001 , 1e9);
        dp[0]=0;
        int n = (int)coins.size();
        for(int i=0 ;i<n;i++){
            for(int j =0 ;j<=amount;j++){
                if((j + 1ll*coins[i]) > amount)continue;
                dp[j + coins[i]] =min(dp[j + coins[i]] , 1 + dp[j]);
            }
        }
        if(dp[amount]==1e9)return -1;
        return dp[amount];
    }
};
