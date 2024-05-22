class Solution {
public:
    bool helper(string & s , string &p , int i , int j){
        if(i == -1 && j ==-1)return true;
        if(i == -1){
            for(int a = j;a>=0;a-=2){
                if(p[a]!='*')return false;
            }
            return true;
        }
        if(j ==-1){
            return false;
        }
        if(s[i]==p[j] || p[j]=='.'){
            return helper(s , p , i-1 , j-1);
        }
        if(p[j]=='*'){
            if(p[j-1]!=s[i] && p[j-1]!='.'){
                return helper(s , p , i ,j-2);
            }
            return helper(s , p , i , j-2) | helper(s , p ,i-1 , j);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return helper(s , p , s.size()-1 , p.size()-1);
    }
};
