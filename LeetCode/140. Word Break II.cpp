class Solution {
public:
    set<string> dp[21][21];
    set<string> helper(int l, int r, unordered_map <string, bool> &mp,string &s){
        if(l > r)return {};
        if(l == r){
            string temp;
            temp += s[l];
            if(mp[temp]){
                return {temp};
            }
            return {};
        }
        if(dp[l][r].size() > 0)return dp[l][r];
        string temp;
        for(int i = l;i<=r;i++){
            temp += s[i];
        }
        if(mp[temp]){
            dp[l][r].insert(temp);
        }
        for(int i = l;i<r;i++){
            set<string> res1 = helper(l,i,mp,s);
            set<string> res2 = helper(i+1,r,mp,s);
            for(auto & it : res2){
                if(!it.size())continue;
                for(auto & it2 : res1){
                    if(!it2.size())continue;
                    dp[l][r].insert(it2 + " " + it);
                }
            }
        }
        return dp[l][r];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>mp;
        for(auto & it : wordDict){
            mp[it] = true;
        }
        int n = (int)s.size();
        set <string> a = helper(0,n-1,mp,s);
        vector<string> ans(a.begin(),a.end());
        return ans;
    }
};
