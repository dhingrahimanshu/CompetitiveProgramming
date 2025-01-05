class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = (int) s.size();

        int l = 'a', r = 'z';

        vector <int> pref(n + 1, 0);

        for (auto &it: shifts) {

            int sign = ((it[2]>0)?1:-1);

            pref[it[0]] += sign;
            pref[it[1] + 1] -= sign;
        }

        for (int i = 1; i <=n; i++) {
            pref[i] += pref[i-1];
        }

        for (int i = 0; i < n; i++) {
            int c = s[i];
            pref[i] %= 26;
            c += pref[i];

            if (c < l) {
                c += 26;
            } else if (c > r){
                c = 'a' + (c % (r + 1));
            }
            // cout << c << endl;

            s[i] = (char) (c);
        }
        return s;
    }
};
