class Solution{
    int dp[101][10001];
    bool helper(int arr[] , int i , int n , int sum ){
        if(sum==0)return 1;
        if(i==n){
            return 0;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        
        return dp[i][sum] = (helper(arr , i+1 , n , sum-arr[i]) || helper(arr , i+1 ,n , sum));
    }
    
    
public:
    int equalPartition(int N, int arr[])
    {
        int sum = accumulate(arr , arr+N , 0);
        memset(dp , -1 ,  sizeof dp);
        if(sum%2==0){
            
            return helper(arr ,0, N , sum/2);
            
        }else{
            return 0;
        }
        
    }
};
