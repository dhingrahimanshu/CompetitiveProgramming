class Solution{
    public:
    
    int maxOnes(int a[], int n)
    {
        int ans =0;
        for(int i =0 ;i<n;i++){
            ans+=a[i];
        }
        int count =0;
        int fans =0;
        for(int i =0 ;i<n;i++){
            if(count<0){
                count=0;
            }
            if(a[i]==0){
                count++;
            }else{
                count--;
            }
            fans = max(fans , count);
        }
        
        
        return fans+ans;
    }
};
