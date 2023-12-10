class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        map <int,int> check;
        
        int sum =0;
        check[sum]=1;
        for(int i=0 ;i<n;i++){
            sum+=arr[i];
            if(check[sum])return true;
            check[sum]=1;
        }
        
        return false;
    }
};
