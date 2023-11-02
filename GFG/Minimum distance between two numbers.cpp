class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        int loc1 = -1;
        int loc2 = -1;
        int ans =INT_MAX;
        
        for(int i =0 ;i<n;i++){
            if(a[i]==x){
                loc1 = i;
            }
            if(a[i]==y){
                loc2=i;
            }
            if(loc1>=0 && loc2>=0){
                ans = min(ans , abs(loc1 - loc2));
            }    
        }
        
        
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
