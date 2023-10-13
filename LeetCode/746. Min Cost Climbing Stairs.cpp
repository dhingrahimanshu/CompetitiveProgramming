class Solution {
public:
    int dp[1001];
    int helper(vector<int> & cost , int stair){
        if(stair<0)return 1e5;
        if(stair==0){
            return cost[0];
        }
        if(stair==1){
            return cost[1];
        }
        if(dp[stair]!=-1){
            return dp[stair];
        }
        return dp[stair] = cost[stair] + min(helper(cost ,stair -1) , helper(cost ,stair -2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp , -1 , sizeof dp);
        int n = (int) cost.size();
        cost.push_back(0);
        return helper(cost , n);
    }
};
