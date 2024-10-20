class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        
        int ans = 0;
        int n = (int) s.size();
        vector<int> freq(26, 0);
        int count = 0;

        int j = 0;
        for (int i = 0;i<n;i++) {
            if (i) {
                if((freq[s[i-1]-'a']--) == k) {
                    count--;
                }
            }
            while (j<n && !count) {
                if (++(freq[s[j]-'a']) == k)count++;
                j++;
            }
            
            if (j == n && !count) {
                break;
            }
            ans += (n - j + 1);
        }
        return ans;
    }
};
