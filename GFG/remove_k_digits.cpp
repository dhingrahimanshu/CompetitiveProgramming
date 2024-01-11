class Solution {
  public:
    string removeKdigits(string S, int K) {
        stack <char> temp;
        for(int i=0;i<(int)S.size();i++){
            if(temp.empty()){
                if(S[i]=='0')continue;
                temp.push(S[i]);
            }else{
                while(K && temp.size() && temp.top()>S[i]){
                    temp.pop();
                    K--;
                }
                if(temp.size() || (temp.empty() && S[i]!='0')){
                    temp.push(S[i]);
                }
                
            }
           
        }
        
        string ans;
        while(temp.size()){
            ans+=temp.top(); temp.pop();
        }
        reverse(ans.begin() , ans.end());
        while(K && ans.size()){
            ans.pop_back();
            K--;
        }
        if(ans.size()==0)return "0";
        return ans;
        
    }
};
