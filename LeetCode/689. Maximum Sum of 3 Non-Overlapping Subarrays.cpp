typedef long long ll;
class Solution {
public:
    int n, K;
    ll dp[20001][3];

    ll getPrefix(vector<ll> &arr, int l, int r) {
        if (!l) return arr[r];
        return arr[r] - arr[l-1];
    }

    ll helper (int level, int pick, vector<ll> & pref) {
        if (pick == 3) return 0;
        if (level == n) {
            return -1e17;
        }
        if (dp[level][pick] != -1) return dp[level][pick];

        dp[level][pick] = helper(level + 1, pick, pref); // don't take

        if ((level + K - 1) < n) {
            dp[level][pick] = max(dp[level][pick], getPrefix(pref, level, level + K - 1) +  helper(level + K, pick + 1, pref));
        }

        return dp[level][pick];
    }

    void printAns (int level, int pick, vector <ll> &pref, vector<int> & ans, ll val) {
        if (pick == 3 || level == n) return ;

        if ((level + K - 1) < n && (val - getPrefix(pref, level, level + K - 1)) == helper(level + K, pick + 1, pref)) {
            ans.push_back(level);
            printAns(level + K, pick + 1, pref, ans, val - getPrefix(pref, level, level + K - 1));
        } else {
            printAns(level + 1, pick , pref, ans, val);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(dp, -1, sizeof dp);
        vector <int> ans;
        n = (int) nums.size();
        K = k;

        vector<ll> pref(n, 0);
        for (int i = 0; i < n; i++) {
            pref[i] = nums[i];
            if (i) pref[i] += pref[i-1];
        }

        ll val = helper (0, 0, pref);
        // cout << val << endl;
        printAns(0, 0, pref, ans, val);

        return ans;
    }
};
