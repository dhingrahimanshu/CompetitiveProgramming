class Solution{
    public:
    int equilibriumPoint(long long a[], int n) {
    
        int sum=0;
        for(int i =0 ;i<n;i++){
            sum+=a[i];
        }
        int sum2=0;
        for(int i=0 ;i<n;i++){
            sum-=a[i];
            if(sum2==sum){
                return i+1;
            }
            sum2+=a[i];
        }
        return -1;
    }

};
