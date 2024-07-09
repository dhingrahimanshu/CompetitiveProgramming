class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int n = (int)colors.size();
        
        vector<int> dp(n + k);
        dp[n + k - 1] = 1;
        for(int i = n+k-2;i>=0;i--){
            if(colors[i%n] != colors[(i+1)%n]){
                dp[i] = 1 + dp[i+1];
            }else{
                dp[i] = 1;
            }
        }
        for(int i = 0;i<n;i++){
            if(dp[i]>=k)ans++;
        }

        return ans;
    }
};
