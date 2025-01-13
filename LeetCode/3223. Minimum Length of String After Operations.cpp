class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;

        vector <int> freq(26, 0);

        for (auto &it: s) {
            freq[it - 'a']++;
        }


        for (auto &it: freq) {
            if (!it) continue;
            if (it & 1) {
                ans++;
            } else {
                ans += 2;
            }
        }
        return ans;
    }
};
