class Solution {
public:
    int dp[101][101][101];

    int helper(int l ,int r  , int cont, vector<int> & boxes){
        if(l>r)return 0;
        
        if(dp[l][r][cont]!=-1)return dp[l][r][cont];

        dp[l][r][cont] = (cont+1)*(cont+1) +helper(l+1 ,r,0 , boxes);

        for(int i = l+1 ;i<=r;i++){
            if(boxes[l]==boxes[i]){
                dp[l][r][cont] = max(dp[l][r][cont] , helper(i ,r, cont+1 , boxes) + helper(l+1 , i-1 , 0 , boxes));
            }
        }
        return dp[l][r][cont];
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp , -1 , sizeof dp);
        int n = (int)boxes.size();
        return helper(0 , n-1 , 0 , boxes);
    }
};
