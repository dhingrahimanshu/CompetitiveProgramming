class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin() , a.end());
        long long ans = 1e16;
        for(int i=0;i<=n-m;i++){
            ans  = min(ans ,a[i+m-1]-a[i]);
        }
        return ans;
    
    }   
};
