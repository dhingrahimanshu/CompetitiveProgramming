class Solution {
public:
    int dp[301][5001];
    int helper(int amount ,int level , vector<int> & coins){
        if(amount==0)return 1;
        if(level==coins.size() || amount<0)return 0;

        if(dp[level][amount]!=-1)return dp[level][amount];

        return dp[level][amount] = helper(amount - coins[level] , level,coins) + helper(amount , level +1 , coins);
    }

    int change(int amount, vector<int>& coins) {
        memset(dp , -1 , sizeof dp);
        return helper(amount , 0 , coins);
    }
};
