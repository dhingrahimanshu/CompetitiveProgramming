class Solution {
public:
    int dp[51][(1<<10)];
    int customers;
    int items;
    vector<int> req;
    int helper (int level, int mask, vector<pair<int,int>> & arr) {
        if (level == items) {
            return (!mask);
        }
        if (dp[level][mask] != -1) return dp[level][mask];

        dp[level][mask] = helper(level + 1, mask, arr);

        for (int submask = mask; submask; submask = (submask - 1)&mask) {
            if (req[submask] <= arr[level].second) {
                // cout << req[submask] <<endl;
                dp[level][mask] |= helper(level + 1, mask^submask, arr);
            }
           
        }

        return dp[level][mask];
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        memset(dp, -1, sizeof dp);

        map <int,int> freq;

        int n = (int)nums.size();
        int m = (int) quantity.size();

        

        for (auto & it: nums) {
            freq[it]++;
        }
        vector<pair<int,int>> arr(freq.begin(), freq.end());
        items = (int)arr.size();
        customers = m;

        req.resize((1<<m), 0);
        for (int i = 0; i<(1<<m); i++) {
            for (int j = 0; j<m; j++) {
                if (i&(1<<j)) {
                    req[i]+=quantity[j];
                }
            }
        }
        // for (auto & it : req) {
        //     cout << it << endl;
        // }

        return helper(0, ((1<<m) - 1), arr);
    }
};
