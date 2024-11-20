class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = (int)s.size();
        int ans = n;
        vector<vector<int>> hash(3);

        for (int i = n - 1; i>=0; i--) {
            hash[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 3; i++) {
            if ((int)hash[i].size() < k) return -1;
        }

        vector <int> state(3, k);
        for (int i = 0; i < n; i++) {
            int a = n;
            for (int j = 0; j < 3; j++) {
                if (state[j] <= 0) continue;
                a = min(a, hash[j][state[j] - 1]);
            }
            
            a = (n - 1 - a + 1);

            ans = min(ans, i + a);
            state[s[i]-'a']--;
        }

        return ans;
    }
};
