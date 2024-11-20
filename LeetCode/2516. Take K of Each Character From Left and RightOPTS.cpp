class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = (int) s.size();

        int maxWindow = 0;
        vector<int> count(3, 0), window(3, 0);

        for (auto & it : s) {
            count[it-'a']++;
        }
        for (int i = 0; i < 3; i++) {
            if (count[i] < k) return -1;
        }

        int left = 0;

        for (int right = 0; right < n; right++) {
            window[s[right]-'a']++;

            while ((count[0] - window[0] < k) || (count[1] - window[1] < k) || (count[2] - window[2]) < k) {
                window[s[left]-'a']--;
                left++;
            }

            maxWindow = max(maxWindow, right - left + 1);
        }

        return n - maxWindow;
    }
};
