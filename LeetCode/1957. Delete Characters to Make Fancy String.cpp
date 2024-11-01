class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int n = (int)s.size();
        for (int i = 0; i < n; ) {
            int j = i;
            while(j<n && s[i]==s[j])j++;
            string temp(min(2, j - i), s[i]);
            ans += temp;
            i = j;
        }

        return ans;
    }
};
