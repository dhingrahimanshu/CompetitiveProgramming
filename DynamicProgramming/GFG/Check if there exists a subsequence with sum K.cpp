class Solution{
    public:
    vector<vector<int>> dp;
    bool rec(int level , vector<int> &arr , int left){
        if(level == (int)arr.size() || left<0){
            return left==0;
        }
        if(dp[level][left]!=-1){
            return dp[level][left];
        }
        int ans =0;
        ans|=rec(level +1 , arr , left - arr[level]);
        ans|=rec(level + 1 , arr , left);

        return dp[level][left] = ans;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        dp.resize(n , vector<int>(k+1 ,-1));
        return rec(0 , arr , k);
    }
};
