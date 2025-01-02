class Solution {
public:

    bool isVowel(char a) {
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector <int> ans;
        int n = (int) words.size();
        vector <int> pref(n, 0);

        for (int i = 0; i < n ;i++) {
            pref[i] = (isVowel(words[i][0]) && isVowel(words[i].back()));
            if (i) pref[i] += pref[i-1];
        }


        for (auto &it: queries) {
            int l = it[0];
            int r = it[1];
            ans.push_back(pref[r] - (l?pref[l-1]:0));
        }

        return ans;
    }
};
