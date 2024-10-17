class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = (int)s.size();

        int ma = -1;
        vector<int> maxAt(n);

        for (int i = n-1;i>=0;i--) {
            if (ma < (s[i] - '0')) {
                maxAt[i] = i;
                ma = (s[i] - '0');
            } else {
                maxAt[i] = maxAt[i+1];
            }
        }

        for (int i = 0;i<n;i++) {
            if (s[i] < s[maxAt[i]]) {
                swap(s[i], s[maxAt[i]]);
                break;
            }
        }
        int ans = stoi(s);
        return ans;

    }
};
