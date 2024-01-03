class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int sum=0 , ans =-1e9 , j =0;
        vector<long long int> suf(n+1 ,0);
        
        for(int i = n-1;i>=0;i--){
            suf[i] = max({0ll ,a[i] , suf[i+1] + a[i]});
        }
        
        for(int i =0 ; i+k<=n;i++){
            if(i){
                sum-=a[i-1];
            }
            while((j-i)<k){
                sum+=a[j];
                j++;
            }
            ans = max(ans , sum + suf[j]);
        }
        
        return ans;
    }
};
