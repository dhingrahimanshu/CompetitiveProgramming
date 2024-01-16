    long long maxSubarraySum(int arr[], int n){
        
        long long ans =-1e9;
        long long sum =0;
        
        for(int i=0 ;i<n;i++){
            sum+=arr[i];
            if(sum<0){
                ans = max(ans , sum);
                sum=0;
            }else{
                ans =max(ans , sum);
            }
        }
        
        return ans;
        
    }
