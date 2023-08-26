class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int ans =-1;
        int i =0 , j=0;
        int n = s.size();
        vector<int> hash(26 ,0);
        int count=0;
        while(i<n){
            if(i){
                hash[(s[i-1]-'a')]--;
                if(hash[s[i-1]-'a']==0){
                    count--;
                }
            }
            while(j<n && count<=k){
                hash[(s[j]-'a')]++;
                if(hash[s[j]-'a']==1){
                    count++;
                }
                if(count>k){
                    count--;
                    hash[s[j]-'a']--;
                    break;
                }
                j++;
            }
            if(count==k){
                ans = max(ans , j - i);
            }
            
            i++;
        }
        
        
        return ans;
        
    }
};
