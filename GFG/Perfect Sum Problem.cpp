class Solution{

	public:
    vector<vector<int>> dp;	
    int const MOD = 1e9+7;
	int knapsack(int arr[] , int i , int sum , int n){
	    
	    if(sum<0)return 0;
	    if(i==n){
	        return (sum==0);
	    }
	    if(dp[i][sum]!=-1){
	        return dp[i][sum];
	    }
	    return dp[i][sum] =(knapsack(arr , i+1 , sum , n) + knapsack(arr , i+1 , sum-arr[i] , n))%MOD;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        dp.resize(n , vector<int>(sum+1 , -1));
        return knapsack(arr , 0 , sum , n);
	}
	  
};
