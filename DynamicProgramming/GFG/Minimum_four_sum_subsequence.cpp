class Solution{
    public:
    int minSum(int arr[], int n){
        if(n<=4){
            return (*min_element(arr , arr+n));
        }
        vector<int> dp(n);
        for(int i =0 ;i<n;i++)dp[i]=arr[i];
        
        for(int i = 4;i<n;i++){
            int ans = INT_MAX;
            for(int j = i-4;j<i;j++){
                ans = min(ans , dp[j]);
            }
            dp[i] +=ans;
        }
        
        int ans =INT_MAX;
        for(int i = n-1;i>=n-4;i--){
            ans = min(ans , dp[i]);
        }
        return ans;
    }
};
