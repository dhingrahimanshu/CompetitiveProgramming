class Solution{
  public:
    int majorityElement(int a[], int size)
    {
        
        int ans =a[0] , count =1;
        for(int i=1 ;i<size;i++){
            if(a[i]==ans)count++;
            else count--;
            if(count==0){
                ans = a[i]; count=1;
            }
        }
        
        count =0;
        for(int i=0 ;i<size;i++){
            if(a[i]==ans)count++;
        }
        
        if(count> size/2)return ans;
        return -1;
    }
};
