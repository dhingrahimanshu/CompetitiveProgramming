class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector <int> swaps;
        int n = (int) s1.size();

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                swaps.push_back(i);
            }
        }
        if (swaps.size() == 0) return true;
        if (swaps.size() != 2) return false;

        if (s1[swaps[1]] == s2[swaps[0]] && s1[swaps[0]] == s2[swaps[1]]) return true;

        return false;
    }
};
