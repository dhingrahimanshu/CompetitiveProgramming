class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = (int) s.size();
        unordered_map <string, int> mpp;
        int jump = n / k;
        for (int i = 0; i < n; i+=jump) {
            string temp;
            for (int j = i; j < i + jump; j++) {
                temp += s[j];
            }
            mpp[temp]++;
        }

        for (int i = 0; i < n; i+=jump) {
            string temp;
            for (int j = i; j < i + jump; j++) {
                temp += t[j];
            }
            if (mpp.find(temp) == mpp.end() || !mpp[temp]) {
                return false;
            }
            mpp[temp]--;
        }


        return true;
    }
};
