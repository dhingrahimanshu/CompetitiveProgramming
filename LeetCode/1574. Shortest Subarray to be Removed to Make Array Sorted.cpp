class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = (int) arr.size();
        vector<int> pref, suf;
        pref.push_back(arr[0]);
        suf.push_back(arr.back());

        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                pref.push_back(arr[i]);
            } else {
                break;
            }
        }

        if ((int)pref.size() == n) return 0;

        for (int i = n-2; i >=0; i--) {
            if (arr[i] <= arr[i + 1]) {
                suf.push_back(arr[i]);
            } else {
                break;
            }
        }
        reverse(suf.begin(), suf.end());
        int ans = max(pref.size(), suf.size());
        // cout << ans << endl;
        for (int i = 0; i < suf.size(); i++) {
            int backEle = suf.size() - i;
            int frontEle = 0;
            auto it = upper_bound(pref.begin(), pref.end(), suf[i]);
            if (it != pref.begin()) {
                --it;
                frontEle = (it - pref.begin() + 1);
            }

            ans = max(ans, backEle + frontEle);
        }

        return n - ans;
    }
};
