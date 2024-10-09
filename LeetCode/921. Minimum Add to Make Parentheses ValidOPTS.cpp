class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int openB = 0;
        for(auto & it : s) {
            if (it == '(') {
                openB++;
            } else {
                if (openB) {
                    openB--;
                } else {
                    ans++;
                }
            }
        }
        return openB + ans;
    }
};
