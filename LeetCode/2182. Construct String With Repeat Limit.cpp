class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = (int)s.size();
        vector <int> freq(26, 0);
        string ans;

        for (auto &it: s) {
            freq[it - 'a']++;
        }

        int j = 25;
        for (int i = 25; i >= 0; i--) {
            if (!freq[i]) continue;

            while (freq[i]) {
                int req = min(repeatLimit, freq[i]);
                string temp(req, (char)(i + 'a'));
                ans += temp;
                freq[i] -= req;

                if (!freq[i]) break;
                j = min(j, i - 1);
                while (j>=0 && !freq[j]) {
                    j--;
                }
                if (j == -1)break;
                ans += (char)('a' + j);
                freq[j]--;
            }
        }

        return ans;
    }
};
