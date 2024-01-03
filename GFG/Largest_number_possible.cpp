class Solution{
public:
    string findLargest(int N, int S){
        if(N>1 && S==0) return "-1";
        int a = S/9;
        int re = S - a*9;
        
        string ans(a , '9');
        
        if((a + (re!=0))<=N){
            if(re){
                ans+= (char)(re +'0');
                a++;
                
            }
            string uf(N-a, '0');
            
            ans+=uf;
        }else{
            return "-1";
        }
        return ans;
        
    }
};
