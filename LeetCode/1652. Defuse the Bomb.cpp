class Solution {
public:

    int getPref (vector<int> & arr, int l, int r) {
        if (l > r) return 0;
        if (!l) return arr[r];
        return arr[r] - arr[l-1];
    }
    vector<int> decrypt(vector<int>& code, int k) {
        int n = (int) code.size();
        vector<int> ans;
        bool flag = false;
        if (k < 0) {
            reverse(code.begin(), code.end());
            k = abs(k);
            flag = true;
        }

        for (int i = 1; i < n; i++) {
            code[i] += code[i-1];
        }

        for (int i = 0; i < n; i++) {
            int l = i + 1, r =  min(n - 1, i + k);
            int l2 = 0, r2 = k - (r - l + 1) - 1;
            
            int ans2 = getPref(code,l , r) + getPref(code, l2, r2);
            ans.push_back(ans2);
        }

        if (flag) {
            reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};
