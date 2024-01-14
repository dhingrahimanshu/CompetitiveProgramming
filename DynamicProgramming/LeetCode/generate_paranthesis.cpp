class Solution {
public:
    vector<string> ans;
    void helper(int open , int close , string & s){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open){
            s+='(';
            helper(open -1 , close , s);
            s.pop_back();
        }
        if(close>open){
            s+=')';
            helper(open , close -1 , s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        helper(n ,n , s);
        return ans;
    }
};
