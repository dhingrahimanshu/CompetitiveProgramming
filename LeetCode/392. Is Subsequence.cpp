class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i =0;
        for(int j =0 ;j<(int)t.size();j++){
            if(t[j]==s[i]){
                i++;
            }
        }

        return (i==(int)s.size());
    }
};
