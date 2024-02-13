class Solution {
public:
    bool check(string & s){
        int n = (int)s.size();
        for(int i = 0;i<n/2;i++){
            if(s[i]!=s[n-i-1])return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto & it  :words){
            if(check(it))return it;
        }
        return "";
    }
};
