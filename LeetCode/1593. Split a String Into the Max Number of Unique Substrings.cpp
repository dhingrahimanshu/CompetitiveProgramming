class Solution {
public:
    unordered_set <string> isMade;
    int ans = 0;
    void helper (int level, string &s) {
        if (level == (int)s.size()){
            ans = max(ans, (int)isMade.size());
            return;
        }
        string temp;
        for (int i = level; i < (int)s.size(); i++) {
            temp += s[i];
            if (isMade.find(temp) == isMade.end()) {
                isMade.insert(temp);
                helper(i + 1, s);
                isMade.erase(temp);
            }
        } 


    }
    int maxUniqueSplit(string s) {
        helper(0,s);
        return ans;
    }
};
