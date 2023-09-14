class Solution{
    public:
    int max_Books(int a[], int n, int k)
    {
        int ans =0;
        
        int count=0;
        for(int i =0 ;i<n;i++){
            if(a[i]>k){
                ans= max(ans , count); 
                count =0;
            }else{
                count+=a[i];
            }
        }
        ans = max(ans , count);
        return ans;
    }
};
