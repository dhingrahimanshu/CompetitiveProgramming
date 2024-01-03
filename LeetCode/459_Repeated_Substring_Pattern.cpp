class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        bool flag =false;
        
        string ans;
        for(int i =0 ;i<s.size()/2;i++){
            ans+=s[i];
            if(s.size()%ans.size()!=0){
                continue;
            }
            bool flag2 = true;
            for(int j =0 ;j<s.size();j+=ans.size()){
                if(ans!=s.substr(j,ans.size())){
                
                    flag2 = false;
                    break;
                }
            }
            flag|=flag2;
        }
        
        return flag;
    }
};
