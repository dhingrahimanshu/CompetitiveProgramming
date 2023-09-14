class Solution
{
public:

    vector<vector<int>> dp;
    int const MOD = 1e9 +7;
    int helper(int x ,int y){
        if(x<0 || y<0){
            return 0;
        }
        if(x==0 && y==0){
            return 1;
        }
        if(dp[x][y]!=-1)return dp[x][y];
        
        return dp[x][y] = (helper(x-1 ,y) + helper(x , y-1))%MOD;
    }

    int ways(int x, int y)
    {
        dp.resize(x+1 , vector<int>(y+1 , -1));
        return helper(x , y);
    }
};
