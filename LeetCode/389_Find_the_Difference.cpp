class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans =0;
        s+=t;
        for(auto it : s){
            ans^=it;
        }
        return ans;
    }
};
