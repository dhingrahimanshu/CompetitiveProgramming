class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        int arr[201] = {0};
        for(int i=0;i<n;i++){
            if(++arr[a[i]] == k)return a[i];
        }
        return -1;
    }
};
