class Solution {
public:
    vector<string> ans;
    vector<string> res;
    map<string,bool> mp;
    void helper(int level,string & s){
        if(level == s.size()){
            string temp;
            for(auto & it : res){
                if(temp.size()){
                    temp += " ";
                }
                temp += it;
            }
            ans.push_back(temp);
            return;
        }
        string uf;
        for(int i = level;i<s.size();i++){
            uf += s[i];
            if(mp[uf]){
                res.push_back(uf);
                helper(i+1,s);
                res.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto & it : wordDict){
            mp[it] = true;
        }
        helper(0,s);
        return ans;
    }
};
