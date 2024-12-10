class Solution {
public:

    bool check (string & s, int window) {
        int n = (int) s.size();

        vector <int> freq(26, 0);
        int unique = 0;
        vector <int> hash(26, 0);
        for (int i = 0; i < window; i++) {
            int ele = s[i] - 'a';
            if (!(freq[ele]++)) {
                unique++;
            }
        }

        if (unique == 1) {
            hash[s[window - 1] - 'a']++;
        }

        for (int i = window; i < n; i++) {
            int rem = s[i - window] - 'a';
            if (!(--freq[rem])) {
                unique--;
            }

            int ele = s[i] - 'a';
            if (!(freq[ele]++)) {
                unique++;
            }

            if (unique == 1) {
                hash[ele]++;
                if (hash[ele] >= 3) return true;
            }
        }
        return false;
        
    }

    int maximumLength(string s) {
        int n = (int)s.size();
        int lo = 1, hi = n;

        int ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            // cout << mid << endl;
            if (check(s, mid)) {
                lo = mid + 1;
                ans = max(ans, mid);
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
