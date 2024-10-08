class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        int n = (int)s1.size();
        int m = (int)s2.size();

        if (n > m) {
            return 0;
        }

        vector<int> arr(26,0);
        for (auto & it : s1) {
            arr[it - 'a']++;
        }
        vector<int> hash(26,0);
        for (int i = 0;i<n;i++) {
            hash[s2[i]-'a']++;
        }

        if (hash == arr) {
            return 1;
        }

        for (int i = n; i < m; i++) {
            hash[s2[i-n]-'a']--;
            hash[s2[i]-'a']++;
            if (hash == arr) return true;
        }

        return false;
    }
};
