class Solution{
    public:
    string colName (long long int n)
    {
        string ans; 
        while(n){
            int temp = n%26;
            if(temp==0){
                ans+='Z';
                n-=1;
            }else{
                ans += (char)(temp +'A' -1);
            }
            
            n=n/26 ;
        }
        
        reverse(ans.begin() , ans .end());
    
        return ans;
    }
    
};
