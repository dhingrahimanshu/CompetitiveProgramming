class Solution{
    public:
    int doUnion(int a[], int n, int b[], int m)  {
        int const c = 1e5 +1;
        int arr[c];
        int ans =0;
        memset(arr , 0 , sizeof arr);
        for(int i =0 ;i<n;i++){
            arr[a[i]]++;
            if(arr[a[i]]==1)ans++;
        }
        for(int i=0 ;i<m;i++){
            arr[b[i]]++;
            if(arr[b[i]]==1)ans++;
        }
        return ans;
    }
};
