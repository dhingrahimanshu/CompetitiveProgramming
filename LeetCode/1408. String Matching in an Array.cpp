class Solution {
public:
    bool isSubstring(string & a, string & b) {
        int n = (int)a.size();
        int m = (int)b.size();

        for (int i = 0; i <= n - m; i++) {
            if (a.substr(i, m) == b) return true;
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector <string> ans;

        int n = (int)words.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n ;j++) {
                if (i == j) continue;
                if (isSubstring(words[j], words[i])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};
