class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int dp[n];
	    for(int i =0 ;i<n;i++){
	        dp[i] = arr[i];
	        int ans =0;
	        for(int j =0 ;j<i;j++){
	            if(arr[j] < arr[i]){
	                ans = max(ans , dp[j]);
	            }
	        }
	        dp[i]+=ans;
	    }
	    return *max_element(dp , dp+n);
	}  
};
