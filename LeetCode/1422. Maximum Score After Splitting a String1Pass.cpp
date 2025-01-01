class Solution {
public:
    int maxScore(string s) {
        int pref = INT_MIN;
        int n = (int) s.size();
        int one = 0;
        int zero = 0;

        for (int i = 0; i < n -1; i++) {
            char it = s[i];
            zero += it == '0';
            one += it == '1';
            pref = max(pref, zero - one);
        }

        if (s[n-1] == '1') one++;

        return pref + one;
    }
};
