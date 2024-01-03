class Solution {
    bool flag = true;
public:
    int lengthOfLastWord(string s) {
        int j = s.size()-1;
        while(j>=0 && s[j]==' '){
            j--;
        }
        int i=0;
        while(j>=0 && s[j]!=' '){
            j--;
            i++;
        }
        return i;
    }
};
