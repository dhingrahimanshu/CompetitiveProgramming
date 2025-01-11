class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) return false;
        vector <int> freq(26, 0);

        for (auto &it: s) {
            freq[it - 'a']++;
        }

        int oddFreq = 0;
        for (auto &it: freq) {
            if (it & 1) oddFreq++;
        }

        return oddFreq <= k;
    }
};
